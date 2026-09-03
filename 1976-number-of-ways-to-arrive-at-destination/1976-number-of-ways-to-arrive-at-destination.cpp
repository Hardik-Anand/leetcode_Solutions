class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,int>>> adj(n);
        for(auto it  : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,LLONG_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        long long mod=1e9+7;
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;
            for(auto it : adj[node]){
                int adjNode=it.first;
                long long edgeWt=it.second;
                if(dis+edgeWt < dist[adjNode]){
                    dist[adjNode]=dis+edgeWt;
                    ways[adjNode]=ways[node];
                    pq.push({dis+edgeWt,adjNode});
                }
                else if(dis+edgeWt==dist[adjNode]){
                    ways[adjNode]=(ways[node]+ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
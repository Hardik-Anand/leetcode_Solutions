class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;  // {stops,{node,price}}
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int price=q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;
                if(price+edgeWt < dist[adjNode] && stops<=k){
                    dist[adjNode]=price+edgeWt;
                    q.push({stops+1,{adjNode,price+edgeWt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
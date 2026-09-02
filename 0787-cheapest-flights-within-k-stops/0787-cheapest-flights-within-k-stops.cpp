class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({0,{src,0}});  // {price{node,flightsTaken}}
        vector<vector<int>> dist(n,vector<int>(k+2,1e9)); // dist[node][flightsTaken]
        dist[src][0]=0;
        while(!pq.empty()){
            int price=pq.top().first;
            int node=pq.top().second.first;
            int flightsTaken=pq.top().second.second;
            pq.pop();
            if(node==dst) return price;
            if(flightsTaken == k+1) continue;

            for(auto it : adj[node]){
                int newNode=it.first;
                int cost=it.second;

                int newPrice=price+cost;
                int newFlights=flightsTaken+1;
                if(newPrice<dist[newNode][newFlights]){
                    dist[newNode][newFlights]=newPrice;
                    pq.push({newPrice,{newNode,newFlights}});
                }
            }
        }
        return -1;
    }
};
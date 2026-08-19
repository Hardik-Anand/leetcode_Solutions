class Solution {
private:
    bool dfs_check(int node,int parent, int color[], vector<vector<int>> &graph){
        if(parent==-1) color[node]=0;
        else color[node]=!color[parent];
        for(auto it : graph[node]){
            if(color[it]==-1){
                if(!dfs_check(it,node,color,graph)) return false;
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs_check(i,-1,color,graph)) return false;
            }
        }
        return true;
    }
};
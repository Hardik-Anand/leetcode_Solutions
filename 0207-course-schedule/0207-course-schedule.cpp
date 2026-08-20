class Solution {
public:
    bool dfsCheck(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>>& adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,pathVis,adj)==true) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); 
            // edge: b → a (must take b before a)
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCheck(i,vis,pathVis,adj)==true) return false;
            }
        }
        return true; // no cycle --> can finish
    }
};
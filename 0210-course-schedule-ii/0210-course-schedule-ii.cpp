class Solution {
public:
    bool dfs(int node, stack<int> &st, vector<int> &vis, vector<int> &pathVis,vector<vector<int>> &adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,st,vis,pathVis,adj)==true) return true;
            }
            else if(pathVis[it]) return true;
        }
        st.push(node);
        pathVis[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); 
            // edge: b → a (must take b before a)
        }
        vector<int> ans;
        stack<int> st;
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,st,vis,pathVis,adj)==true) return {};
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
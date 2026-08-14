class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int drow[], int dcol[]){
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) dfs(nrow,ncol,vis,grid,drow,dcol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int j=0;j<n;j++){
            if(vis[0][j]==0 && grid[0][j]==1) dfs(0,j,vis,grid,drow,dcol);
            if(vis[m-1][j]==0 && grid[m-1][j]==1) dfs(m-1,j,vis,grid,drow,dcol);
        }
        for(int i=0;i<m;i++){
            if(vis[i][0]==0 && grid[i][0]==1) dfs(i,0,vis,grid,drow,dcol);
            if(vis[i][n-1]==0 && grid[i][n-1]==1) dfs(i,n-1,vis,grid,drow,dcol);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1)  ans++;
            }
        }
        return ans;
    }
};
class Solution {
private:
    void dfs(int row,int col, vector<vector<int>> &vis,vector<vector<char>>& board,int drow[],int dcol[]){
        vis[row][col]=1;
        int m=vis.size();
        int n=vis[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && board[nrow][ncol]=='O') dfs(nrow,ncol,vis,board,drow,dcol);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int drow[]={-1,0,+1,0};
        int dcol[]={0,1,0,-1};
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && vis[0][j]==0) dfs(0,j,vis,board,drow,dcol);
            if(board[m-1][j]=='O' && vis[m-1][j]==0) dfs(m-1,j,vis,board,drow,dcol);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && vis[i][0]==0) dfs(i,0,vis,board,drow,dcol);
            if(board[i][n-1]=='O' && vis[i][n-1]==0) dfs(i,n-1,vis,board,drow,dcol);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
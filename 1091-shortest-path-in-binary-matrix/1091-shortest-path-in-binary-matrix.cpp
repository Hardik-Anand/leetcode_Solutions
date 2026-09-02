class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int src[2]={0,0};
        int dest[2]={n-1,n-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src[0],src[1]}});
        if(grid[src[0]][src[1]] == 1 || grid[dest[0]][dest[1]] == 1) return -1;

        if(src[0] == dest[0] && src[1] == dest[1]) return 1;

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[src[0]][src[1]]=0;
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                    if(nrow!=0 && ncol!=0){          // for diagonal movements
                        if(dist[nrow][ncol]>dis+2){
                            dist[nrow][ncol]=dis+2;
                            if(nrow==dest[0] && ncol==dest[1]) return dis+2;
                            q.push({dis+1,{nrow,ncol}});
                        }
                    }
                    else if(dist[nrow][ncol]>dis+1){
                        dist[nrow][ncol]=dis+1;
                        if(nrow==dest[0] && ncol==dest[1]) return dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
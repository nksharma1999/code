class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int coutfree=0;
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    coutfree++;
                else{
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }
                }
            }
        }
        if(coutfree==0)
            return 0;
        vector<vector<int>> move={{0,1}, {0,-1}, {-1, 0}, {1, 0}};
        int res=0;
        while(!q.empty()){
            res++;
            int qsize=q.size();
            while(qsize--){
                auto [i,j]=q.front();
                q.pop();
                for(auto g:move){
                    int x=i+g[0];
                    int y=j+g[1];
                    if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        coutfree--;
                    }
                }
            }
            
            if(coutfree==0)
                break;
        }
        
        if(coutfree!=0)
            return -1;
    
        return res;
    }
};

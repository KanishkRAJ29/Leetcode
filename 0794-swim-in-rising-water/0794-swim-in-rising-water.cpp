class Solution {
    typedef pair<int,pair<int,int>> pp;

    bool possible(int h,vector<vector<int>> grid){
        int n = grid.size();
        if(grid[0][0]>h) return 0;
        queue<pp> qe;
        qe.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));

        while(!qe.empty()){
            int s = qe.size();

            while(s--){
                int x = qe.front().first;
                int a = qe.front().second.first;
                int b = qe.front().second.second;
                qe.pop();

                // top
                if(a-1>=0 && !vis[a-1][b]){
                    int k = grid[a-1][b];
                    if(k<=h){
                        qe.push({k,{a-1,b}});
                        vis[a-1][b]=1;
                    }
                }

                // bot

                if(a+1<n && !vis[a+1][b]){
                    int k = grid[a+1][b];
                    if(k<=h){
                        qe.push({k,{a+1,b}});
                        vis[a+1][b]=1;
                    }
                }

                // left

                if(b-1>=0 && !vis[a][b-1]){
                    int k = grid[a][b-1];
                    if(k<=h){
                        qe.push({k,{a,b-1}});
                        vis[a][b-1]=1;
                    }
                }

                // right

                if(b+1<n && !vis[a][b+1]){
                    int k = grid[a][b+1];
                    if(k<=h){
                        qe.push({k,{a,b+1}});
                        vis[a][b+1]=1;
                    }
                }


            }


        }

        return vis[n-1][n-1];
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();

        for(int i=1;i<=n*n;i++){
            if(possible(i,grid)) return i;
        }

        return 0;
    }
};
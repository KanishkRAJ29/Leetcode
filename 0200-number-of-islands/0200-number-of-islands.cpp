class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]==1||grid[i][j]=='0'){
            return;
        }
        vis[i][j]=1;
        dfs(vis,grid,i+1,j);
        dfs(vis,grid,i-1,j);
        dfs(vis,grid,i,j-1);
        dfs(vis,grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    count++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return count;

    }
};
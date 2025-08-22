class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left=INT_MAX;
        int right=INT_MIN;
        int up=INT_MAX;
        int down=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    left=min(i,left);
                    right=max(i,right);
                    up=min(j,up);
                    down=max(j,down);

                }
            }
        }
        int row=0;
        int col=0;
       
        
        row=right-left+1;
        col=down-up+1;
        return col*row;
    }
};
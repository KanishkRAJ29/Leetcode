class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int dir,int chance,int prev){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==1)return 0;
        if(prev==1||prev==0){
            if(grid[i][j]!=2)return 0;
        }
        else if(prev==2){
            if(grid[i][j]!=0)return 0;
        }

        int curr=grid[i][j];
        int moveNext=0;
        int change=0;
        if(chance !=0){
        int newDir=(dir+1)%4;
        if(newDir==0){
            change=solve(i-1,j-1,grid,0,0,curr);}
        else if(newDir==1){
                    change=solve(i-1,j+1,grid,1,0,curr);}
        else if(newDir==2){
                   change=solve(i+1,j+1,grid,2,0,curr);}
        else {  change=solve(i+1,j-1,grid,3,0,curr);}
        }
        if(dir==0){
            moveNext=solve(i-1,j-1,grid,0,chance,curr);}
        else if(dir==1){
                    moveNext=solve(i-1,j+1,grid,1,chance,curr);}
        else if(dir==2){
                   moveNext=solve(i+1,j+1,grid,2,chance,curr);}
        else {  moveNext=solve(i+1,j-1,grid,3,chance,curr);}
        

        return 1+max(moveNext,change);
        
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int upLeft=solve(i-1,j-1,grid,0,1,1);
                    int upRight=solve(i-1,j+1,grid,1,1,1);
                    int downRight=solve(i+1,j+1,grid,2,1,1);
                    int downLeft=solve(i+1,j-1,grid,3,1,1);
                    int neigh=max({upLeft,upRight,downRight,downLeft});
                    ans=max(ans,1+neigh);
                }
            }
        }
        return ans;
    }
};
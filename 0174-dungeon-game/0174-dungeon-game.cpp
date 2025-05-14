class Solution {
public:
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& d){
        if(i>=d.size()||j>=d[0].size()){
            return INT_MAX;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(i==d.size()-1&&j==d[0].size()-1){
            if(d[i][j]<=0){
                return  abs(d[i][j])+1;
            }else return 1;
        }
        int down=solve(i+1,j,d);
        int right=solve(i,j+1,d);
        int val=min(down,right);
        int curr=d[i][j];
        int res=val-curr;
        return t[i][j]=max(1, val - curr);

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
    }
};
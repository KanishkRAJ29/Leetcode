class Solution {
public:
    int M,N;
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i>=M||j>=N)return 0;
        if(i==M-1||j==N-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(i+1,j,dp)+solve(i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        M=m;
        N=n;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dp);
    }
};
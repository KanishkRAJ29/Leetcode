/*class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];

    }
};*//*class Solution {
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
};*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,1);
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[j] = dp[j] + dp[j + 1];
            }
        }
        return dp[0];
    }
};
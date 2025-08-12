class Solution {
public:
        int mod=1e9+7;
   long long power_with_limit(long long base, int exp, long long limit) {
        long long res = 1;
        for (int k = 0; k < exp; ++k) {
            res *= base;
            if (res > limit) return res; // early return if > limit
        }
        return res;
    }
    int numberOfWays(int n, int x) {
        if (n == 0) return 1;

        // compute max base i such that i^x <= n (integer way)
        int maxI = 0;
        for (int i = 1;; ++i) {
            long long p = power_with_limit(i, x, n);
            if (p > n) break;
            maxI = i;
        }
        if (maxI == 0) return 0;

        // dp[i][s] = ways to make sum 's' using bases i..maxI
        vector<vector<int>> dp(maxI + 2, vector<int>(n + 1, 0));
        dp[maxI + 1][n] = 1; 
        int N=n;
        for(int i=maxI;i>0;i--){
            long long p=power_with_limit(i,x,n);
            for(int j=n;j>=0;j--){
                int take=0;
                if(j+p<=N)take=dp[i+1][j+p];
                dp[i][j]=(take+dp[i+1][j])%mod;
            }
        }
        return dp[1][0];

    }
};/*
class Solution {
public:
    int mod=1e9+7;
    long long power(long long base, int exp) {
        if(exp==1)return base;
        if(base==1||exp==0)return 1;
       if(exp%2==0){
        return power(base*base,exp/2);
       }else return base*power(base*base,(exp-1)/2);

    }
    int solve(int i,int currSum,int x,int n,vector<vector<int>>&dp){
        long long p=power((long long )i,x);
        if(currSum==n)return 1;
        if(p>n||currSum>n)return 0;
        if(dp[i][currSum]!=-1)return dp[i][currSum];

        int take=0;
        if(currSum+p<=n){
            take=solve(i+1,currSum+p,x,n,dp)%mod;
        }
        int skip=solve(i+1,currSum,x,n,dp)%mod;
        return dp[i][currSum]=(skip+take)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,0,x,n,dp);
    }
};*/
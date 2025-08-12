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
};
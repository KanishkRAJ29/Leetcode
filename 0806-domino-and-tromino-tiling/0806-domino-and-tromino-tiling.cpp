class Solution {
public:
    int mod=1e9+7;
    long helper(int n, vector<long>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        if(dp[n]!=-1) return dp[n]%mod;

        long smallAns1=0, smallAns2=0;
        smallAns1=helper(n-1,dp)%mod;
        smallAns2=helper(n-3,dp)%mod;

        dp[n]=(smallAns1*2+smallAns2)%mod;
        return dp[n]%mod;
    }
    
    int numTilings(int n) {
        vector<long> dp(n+1,-1);
        long ans=helper(n,dp)%mod;
        return (int)ans;        
    }
};
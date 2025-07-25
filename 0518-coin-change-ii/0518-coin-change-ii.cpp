/*class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        int n=amount;
        vector<vector<int>>dp(m+1,vector<int>(amount+1,0));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0){
                   dp[i][j]=1; 
                }
                if(i==0){
                    dp[i][j]=0;
                }
            }
        }
        dp[0][0]=1;
          for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
          }
        return dp[m][n];
    }
};
*/

class Solution {
public:
    vector<vector<int>>dp;
    int memo(int amount,int ind,vector<int>&coins){
        if(amount == 0)return 1;
        if(ind < 0 || amount < 0)return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int pick = memo(amount - coins[ind],ind,coins);
        int notpick = memo(amount,ind-1,coins);

        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return memo(amount,n-1,coins);
    }
};
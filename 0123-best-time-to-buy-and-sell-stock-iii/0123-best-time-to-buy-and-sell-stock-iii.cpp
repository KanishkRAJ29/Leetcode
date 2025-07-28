class Solution {
public:
    int dp[100001][2][3];
 int solve(vector<int>&prices,int currIndex, int hold,int leftT){
        if(currIndex>=prices.size() ||leftT==0) return 0;
        if(dp[currIndex][hold][leftT] != -1) return dp[currIndex][hold][leftT];
        if(hold==1){
            int skip = solve(prices,currIndex+1,hold,leftT);
            int sell = solve(prices,currIndex+1,0,leftT-1) + prices[currIndex];
            return dp[currIndex][hold][leftT]=max(sell,skip);
        }else{
            int buy =  solve(prices,currIndex+1,1,leftT)-prices[currIndex];
            int skip = solve(prices,currIndex+1,0,leftT);
            return dp[currIndex][hold][leftT]=max(buy ,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,2);   
    }
};
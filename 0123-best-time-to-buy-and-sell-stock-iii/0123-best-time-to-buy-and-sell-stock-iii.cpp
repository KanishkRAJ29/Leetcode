class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>next(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));
        
        for (int i = prices.size() - 1; i >=0 ; i--) {
            for (int hold = 0; hold <= 1; hold++) {
                for (int j = 1; j <= 2; j++) {
                    if (hold == 1) {
                        int sell = next[0][j - 1] + prices[i];
                        int skip = next[1][j];
                        
                        curr[hold][j] = max(sell, skip);
                    } else {
                        int buy = next[1][j] - prices[i];
                        int skip = next[0][j];
                        
                        curr[hold][j] = max(buy, skip);
                    }
                }
            }
            next=curr;
        }
        return curr[0][2];
    }
};
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int i = prices.size() - 1; i >=0 ; i--) {
            for (int hold = 0; hold <= 1; hold++) {
                for (int j = 1; j <= 2; j++) {
                    if (hold == 1) {
                        int sell = dp[i +1][0][j - 1] + prices[i];
                        int skip = dp[i +1][1][j];
                        
                        dp[i][hold][j] = max(sell, skip);
                    } else {
                        int buy = dp[i + 1][1][j] - prices[i];
                        int skip = dp[i + 1][0][j];
                        
                        dp[i][hold][j] = max(buy, skip);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
}; *//*class Solution {
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
 };*/
class Solution {
public:

    vector<vector<int>>dp;
    int solve(int i, int bought,vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        if(dp[i][bought]!=-1)return dp[i][bought];
        int sell=0,buy=0;
        if (bought) {

                // Sell and reset bought
                 sell=nums[i]+solve(i + 1, 0, nums);
            
        } else {
            // Buy
            
              buy=-nums[i]+solve(i + 1, 1, nums);
        }

        // Skip current day
        int skip=solve(i + 1, bought, nums);
        return dp[i][bought]=max({skip,buy,sell});
    }
    
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // Base case:
    // dp[0][0]: Max profit on day 0 with no stock in hand = 0
    // dp[0][1]: Max profit on day 0 after buying the stock = -prices[0]
    dp[0][0] = 0;              
    dp[0][1] = -prices[0];     

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            int buy = 0, sell = 0;

            if (j == 0) {
                // If we are in "not holding" state:
                // Either skip today => dp[i-1][0]
                // Or sell the stock today => prices[i] + dp[i-1][1]
                sell = prices[i] + dp[i - 1][1];
                dp[i][j] = max(dp[i - 1][j], sell);
            } else {
                // If we are in "holding" state:
                // Either skip today => dp[i-1][1]
                // Or buy stock today => -prices[i] + dp[i-1][0]
                buy = -prices[i] + dp[i - 1][0];
                dp[i][j] = max(dp[i - 1][j], buy);
            }
        }
    }

    // Return profit at last day in "not holding" state
    return dp[n - 1][0];
}

};
/*class Solution {
public:

    vector<vector<int>>dp;
    vector<vector<int>>sellDP;
    int solve(int i, int bought,vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        if(dp[i][bought]!=-1)return dp[i][bought];
        int sell=0,buy=0;
        if (bought) {
           
            
                // Sell and reset bought
                 sell=nums[i]+solve(i + 1, 0, nums);
            
        } else {
            // Buy
            
              buy=-nums[i]+solve(i + 1, 1, nums);
        }

        // Skip current day
        int skip=solve(i + 1, bought, nums);
        return dp[i][bought]=max({skip,buy,sell});
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1,vector<int>(2,-1));
        
        return solve(0, 0, prices);
       
    }
};
*/
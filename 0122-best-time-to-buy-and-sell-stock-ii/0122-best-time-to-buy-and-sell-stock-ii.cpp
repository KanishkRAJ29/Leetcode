class Solution {
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

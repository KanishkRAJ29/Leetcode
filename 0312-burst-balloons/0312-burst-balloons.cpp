class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int>& nums) {
        // If no balloon to burst
        if (left + 1 == right)
            return 0;

        // Return cached result if available
        if (dp[left][right] != -1)
            return dp[left][right];

        int maxi = 0;

        // Choose each balloon between left and right as the last to burst
        for (int i = left + 1; i < right; i++) {
            int leftCost = solve(left, i, nums);
            int rightCost = solve(i, right, nums);
            int currentCost = nums[left] * nums[i] * nums[right];
            maxi = max(maxi, leftCost + rightCost + currentCost);
        }

        // Memoize and return the result
        dp[left][right] = maxi;
        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        // Step 1: Add virtual balloons with value 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        // Step 2: Create a 2D DP table initialized to 0
        // dp[left][right] = max coins from bursting balloons between left and
        // right
        vector<vector<int>> dp(n, vector<int>(n, 0));


        for (int left = n-1; left >=0; left--) {
            for (int right = left+1; right < n; ++right) {
                

            
                for (int i = left + 1; i < right; ++i) {
                   
                    int coins = nums[left] * nums[i] * nums[right];

                  
                    coins += dp[left][i] + dp[i][right];

                   
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

       
        return dp[0][n - 1];
    } /* int maxCoins(vector<int>& nums) {
         // Add virtual balloons with value 1 at both ends
         nums.insert(nums.begin(), 1);
         nums.push_back(1);

         int n = nums.size();

         // Initialize memoization table
         dp.resize(n, vector<int>(n, -1));

         // Solve the problem for the full range
         return solve(0, n - 1, nums);
     }*/
};

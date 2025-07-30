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
        // dp[left][right] = max coins from bursting balloons between left and right
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Step 3: Iterate on window length (minimum length is 3 because we need at least one balloon between left and right)
        for (int length = 2; length < n; ++length) {
            for (int left = 0; left + length < n; ++left) {
                int right = left + length;

                // Step 4: Try each balloon in (left+1, right-1) as the last to burst
                for (int i = left + 1; i < right; ++i) {
                    // Coins from bursting balloon i last in the interval
                    int coins = nums[left] * nums[i] * nums[right];

                    // Total coins = left interval + right interval + current burst
                    coins += dp[left][i] + dp[i][right];

                    // Take the maximum over all choices of i
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        // Step 5: Return result for the full range (excluding added 1s at the ends)
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

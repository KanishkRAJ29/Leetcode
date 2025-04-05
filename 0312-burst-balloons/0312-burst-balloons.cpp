class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int>& nums) {
        // If no balloon to burst
        if (left + 1 == right) return 0;
        
        // Return cached result if available
        if (dp[left][right] != -1) return dp[left][right];
        
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
        // Add virtual balloons with value 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        
        // Initialize memoization table
        dp.resize(n, vector<int>(n, -1));
        
        // Solve the problem for the full range
        return solve(0, n - 1, nums);
    }
};

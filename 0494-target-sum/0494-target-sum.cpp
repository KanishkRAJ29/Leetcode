class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: If target is out of range
        if (abs(target) > totalSum) return 0;

        // Initialize dp array with INT_MIN
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));
        dp[0][nums[0]+totalSum]=1;
        dp[0][-nums[0]+totalSum]+=1;
        for(int i=1;i<nums.size();i++){
            for(int sum=-totalSum;sum<=totalSum;sum++){
                
                if(dp[i-1][sum+totalSum]>0){
                    dp[i][sum + nums[i]+totalSum] += dp[i - 1][sum+totalSum];
                    dp[i][sum - nums[i]+totalSum] += dp[i - 1][sum+totalSum];
                }
            }
        }
        return dp[nums.size()-1][target + totalSum];

    }
};

/*class Solution {
public:
    int totalSum; // Total sum of all elements in nums
    int solve(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        // Memoization check
        if (dp[index][sum + totalSum] != INT_MIN) {
            return dp[index][sum + totalSum];
        }

        // Recursive calls for adding and subtracting current number
        int plus = solve(nums, index + 1, sum + nums[index], target, dp);
        int minus = solve(nums, index + 1, sum - nums[index], target, dp);

        // Store result in dp table
        return dp[index][sum + totalSum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: If target is out of range
        if (abs(target) > totalSum) return 0;

        // Initialize dp array with INT_MIN
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));

        // Start recursion with index = 0 and initial sum = 0
        return solve(nums, 0, 0, target, dp);
    }
};
*/
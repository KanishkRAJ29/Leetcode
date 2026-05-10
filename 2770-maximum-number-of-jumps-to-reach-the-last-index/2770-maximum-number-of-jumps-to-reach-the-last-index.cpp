class Solution {
public:

    int solve(vector<int>& dp, vector<int>& nums, int i, int target) {

        int n = nums.size();

        // reached end successfully
        if(i == n - 1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = -1e9;

        for(int j = i + 1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int next = solve(dp, nums, j, target);
                if(next != -1e9) {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = solve(dp, nums, 0, target);

        return (ans < 0 ? -1 : ans);
    }
};
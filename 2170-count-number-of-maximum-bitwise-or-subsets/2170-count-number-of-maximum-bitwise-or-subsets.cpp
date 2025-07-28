class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for (int x : nums) maxOR |= x;

        // OR values will range from 0 to maxOR (max 2^17 ~ 131072)
        vector<vector<int>> dp(n + 1, vector<int>(maxOR + 1, 0));
        dp[0][0] = 1; // 0 elements, OR = 0

        for (int i = 0; i < n; i++) {
            for (int or_val = 0; or_val <= maxOR; or_val++) {
                if (dp[i][or_val] == 0) continue;

                // Skip current number
                dp[i + 1][or_val] += dp[i][or_val];

                // Take current number
                int new_or = or_val | nums[i];
                dp[i + 1][new_or] += dp[i][or_val];
            }
        }

        return dp[n][maxOR];
    }
};
/*class Solution {
public:
    int solve(int i,int val,int maxval,vector<int>&nums,vector<vector<int>>&dp){
        if(val==maxval)return 1<<(nums.size()-i);
        if(i>=nums.size())return 0;
        if(dp[i][val]!=-1)return dp[i][val];
        int take=solve(i+1,val|nums[i],maxval,nums,dp);
        int skip=solve(i+1,val,maxval,nums,dp);
        return dp[i][val]=take+skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxval=0;
        for(int i=0;i<nums.size();i++){
            maxval|=nums[i];
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(maxval+1,-1));
        return solve(0,0,maxval,nums,dp);
    }
};*/
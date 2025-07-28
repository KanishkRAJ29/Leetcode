class Solution {
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
};
class Solution {
private:
        bool solveMem(int index,vector<int>& nums,int n,int target,vector<vector<int>> &dp)
    {
        //base case
        if(index>=n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;

        if(dp[index][target]!=-1) return dp[index][target];

        bool include=solveMem(index+1,nums,n,target-nums[index],dp);
        bool exclude=solveMem(index+1,nums,n,target,dp);

        return dp[index][target]=include or exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++)
        {
            totalsum+=nums[i];
        }
        if(totalsum%2!=0){
            return 0;
        }
        
        int target=totalsum/2;

        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solveMem(0,nums,n,target,dp);
    }
};
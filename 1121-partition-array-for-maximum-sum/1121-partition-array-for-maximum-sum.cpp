class Solution {
public:
int N;
    int solve(int left,vector<int>&dp,vector<int>&nums,int k){
        if(left>N-1)return 0;
        if(dp[left]!=-1)return dp[left];
        int maxSum=0;
       
        int currMax=-1;
        for(int i=left;i<=min(N-1,left+k-1);i++){
            currMax=max(currMax,nums[i]);
            int currSum=((i-left+1)*currMax)+solve(i+1,dp,nums,k);

            maxSum=max(maxSum,currSum);
        }
        return dp[left]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        N=n-1;
        vector<int>dp(n+1,0);
        for(int left=N;left>=0;left--){
            int maxSum=0;
            int currMax=-1;
            for(int i=left;i<=min(N,left+k-1);i++){
                
                currMax=max(currMax,arr[i]);
                int currSum=((i-left+1)*currMax)+dp[i+1];
                maxSum=max(maxSum,currSum);
            }
            dp[left]=maxSum;
        }
        return dp[0];
       // vector<int>dp(n,-1);
        //return solve(0,dp,arr,k);
    }
};
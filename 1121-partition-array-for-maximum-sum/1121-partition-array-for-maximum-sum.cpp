class Solution {
public:
    int solve(int left,int right,vector<int>&nums,int k){
        if(left>right)return 0;
        int maxSum=0;
       
        int currMax=-1;
        for(int i=left;i<=min(right,left+k-1);i++){
            currMax=max(currMax,nums[i]);
            int currSum=((i-left+1)*currMax)+solve(i+1,right,nums,k);

            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        return solve(0,n-1,arr,k);
    }
};
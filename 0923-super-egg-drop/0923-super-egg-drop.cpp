class Solution {
public:
    int solve(int eggs,int numOfFloorsToSearch,vector<vector<int>>&dp){
        if(numOfFloorsToSearch==0||numOfFloorsToSearch==1) return numOfFloorsToSearch;
        if(eggs==1)return numOfFloorsToSearch;
        if(dp[eggs][numOfFloorsToSearch]!=-1){
            return dp[eggs][numOfFloorsToSearch];
        }
        int ans=INT_MAX;
       /* for(int floor=1;floor<=numOfFloorsToSearch;floor++){
            int currCost=1+max(solve(eggs-1,floor-1,dp),solve(eggs,numOfFloorsToSearch-floor,dp));
            ans=min(ans,currCost);
        }*/
        int low=1;
        int high=numOfFloorsToSearch;
        while(low<=high){
            int mid=low+(high-low)/2;
            int left=solve(eggs-1,mid-1,dp);
            int right=solve(eggs,numOfFloorsToSearch-mid,dp);
            int currCost=1+max(left,right);
            if(left<right){
                low=mid+1;
            }else{
                high=mid-1;
            }
            ans=min(ans,currCost);
        }
        return  dp[eggs][numOfFloorsToSearch]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};
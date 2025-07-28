class Solution {
public:
    int solve(int i,int val,int maxval,vector<int>&nums){
        if(val==maxval)return 1<<(nums.size()-i);
        if(i>=nums.size())return 0;
        int take=solve(i+1,val|nums[i],maxval,nums);
        int skip=solve(i+1,val,maxval,nums);
        return take+skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxval=0;
        for(int i=0;i<nums.size();i++){
            maxval|=nums[i];
        }
        return solve(0,0,maxval,nums);
    }
};
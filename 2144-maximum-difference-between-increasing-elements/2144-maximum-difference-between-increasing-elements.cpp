class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxD=INT_MIN;
        vector<int>minArr(nums.size(),INT_MAX);
        minArr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            minArr[i]=min(minArr[i-1],nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==minArr[i])continue;
            maxD=max(maxD,nums[i]-minArr[i]);
        }
        return (maxD==INT_MIN)?-1:maxD;
    }
};
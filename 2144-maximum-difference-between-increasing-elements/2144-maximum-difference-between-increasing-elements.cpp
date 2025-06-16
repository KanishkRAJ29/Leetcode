class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxD=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    maxD=max(maxD,nums[j]-nums[i]);
                }
            }
        }
        return (maxD==INT_MIN)?-1:maxD;
    }
};
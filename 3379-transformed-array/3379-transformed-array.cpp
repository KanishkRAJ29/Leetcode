class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>result(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int nextind=0;
            if(nums[i]>0){
                nextind=i+nums[i];
                nextind%=n;
                result[i]=nums[nextind];
            }
            else if(nums[i]<0){
                nextind=i-abs(nums[i]);
                while(nextind<0)nextind=n+nextind;
                result[i]=nums[nextind];
            }
        }
        return result;
    }
};
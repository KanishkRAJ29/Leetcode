class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int mini_of_curr_group=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-mini_of_curr_group>k){
                ans++;
                mini_of_curr_group=nums[i];
            }
        }
        return ans;
    }
};
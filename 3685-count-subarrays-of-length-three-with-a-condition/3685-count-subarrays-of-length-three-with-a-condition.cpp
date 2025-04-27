class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=1;
        int k=2;
        if(nums.size()<3)return -1;
        int ans=0;
        int mid=0;
        for(k;k<nums.size();k++){
            if(nums[j]%2==0){
                
                if(nums[i]+nums[k]==nums[j]/2)ans++; 
            }
           
           
            i++;
            j++;
        }
        return ans;
    }
};
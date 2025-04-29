class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int maxi=*max_element(nums.begin(),nums.end());
        
        int i=0;
        int j=0;
        int count=0;
        while(j<nums.size()){
            if(nums[j]==maxi)count++;
            while(i<=j&&count>=k){
                if(nums[i]==maxi)count--;
                i++;
                ans+=nums.size()-j;
            }
            
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini=-1;
        int maxi=-1;
        int badi=-1;
        long long ans=0;
        int smaller=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK){
                badi=i;
            }
            if(nums[i]==minK)mini=i;
            if(nums[i]==maxK)maxi=i;
            smaller=min(mini,maxi);
            ans+=max(0,smaller-badi);
        }
        return ans;

    }
};
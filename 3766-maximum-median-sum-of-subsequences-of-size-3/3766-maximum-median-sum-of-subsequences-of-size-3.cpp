class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
           long long ans=0;
        int j=n-1;
        for(int i=1;i<n;i+=2){
            if(nums[i]==0)break;
            nums[j]=0;
            j--;
           ans+=nums[i];
        }
        return ans;
        
    }
};
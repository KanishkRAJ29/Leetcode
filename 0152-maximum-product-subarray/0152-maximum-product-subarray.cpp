class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double pre=1;
        double suff=1;
        double ans=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return (int) ans;
    }
};
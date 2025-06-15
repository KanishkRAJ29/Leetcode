class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
            long long ans=LLONG_MIN;

        if(m==1){
            long long maxi=0;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,(long long)abs(nums[i]));
            }
            return maxi*maxi;
        }
        else{
            long long mini=LLONG_MAX;
            long long maxi=LLONG_MIN;
            for(int j=m-1;j<nums.size();j++){
                int i=j-m+1;
                maxi=max(maxi,(long long)nums[i]);
                mini=min(mini,(long long)nums[i]);
                long long p1=maxi*nums[j];
                long long p2=mini*nums[j];
                ans=max(ans,max(p1,p2));
            }
        }
        return ans;
    }
};
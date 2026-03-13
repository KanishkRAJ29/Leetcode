class Solution {
public:
double eps = 1e-7;
    long long minNumberOfSeconds(int H, vector<int>& nums) {
        int maxWorkerTime=*max_element(nums.begin(),nums.end());
        long long l =1,r=static_cast<long long>(maxWorkerTime)*H*(H+1)/2;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            long long cnt=0;
            for(int t:nums){
                long long work=mid/t;
                long long k=(-1+sqrt(1+work*8))/2+eps;
                cnt+=k;
            }
             if (cnt >= H) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
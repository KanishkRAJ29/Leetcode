class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            // Shrink the window while (sum * length) >= k
            while (i <= j && sum * (j - i + 1LL) >= k) {
                sum -= nums[i];
                ++i;
            }
            // Now every subarray ending at j, of length 1..(j-i+1), is valid:
            ans += (j - i + 1LL);
        }
        return ans;
    }
};

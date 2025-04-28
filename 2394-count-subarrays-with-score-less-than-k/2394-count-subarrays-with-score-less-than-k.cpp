class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long abtk = 0;
        int i = 0, j = 0;
        int n = nums.size();
        // ← change pSum to long long to avoid overflow
        vector<long long> pSum(n, 0);
        pSum[0] = nums[0];
        for (int t = 1; t < n; ++t) {
            pSum[t] = pSum[t - 1] + nums[t];
        }

        while (j < n) {
            // compute score in 64-bit
            if (i != 0) {
                abtk = (pSum[j] - pSum[i - 1]) * (long long)(j - i + 1);
            } else {
                abtk = pSum[j] * (long long)(j + 1);
            }

            // shrink window while score ≥ k
            while (i <= j && abtk >= k) {
                ++i;
                if (i <= j) {
                    if (i != 0)
                        abtk = (pSum[j] - pSum[i - 1]) * (long long)(j - i + 1);
                    else
                        abtk = pSum[j] * (long long)(j + 1);
                }
            }

            ans += (j - i + 1);
            ++j;
        }

        return ans;
    }
};

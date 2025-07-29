class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> last(32, -1); // track last index each bit was seen

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    last[b] = i; // this bit was last seen here
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) {
                    maxReach = max(maxReach, last[b]);
                }
            }

            ans[i] = maxReach - i + 1;
        }

        return ans;
    }
};

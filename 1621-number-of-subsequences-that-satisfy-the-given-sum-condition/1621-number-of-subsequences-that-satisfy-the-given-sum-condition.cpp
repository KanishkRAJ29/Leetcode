class Solution {
public:
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int mod = 1e9 + 7;
    vector<int> pow2(nums.size(), 1);
    
    // Precompute powers of 2
    for (int i = 1; i < nums.size(); ++i)
        pow2[i] = (pow2[i - 1] * 2) % mod;

    int ans = 0;
    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            ans = (ans + pow2[right - left]) % mod;
            left++;
        } else {
            right--;
        }
    }
    return ans;
}

};
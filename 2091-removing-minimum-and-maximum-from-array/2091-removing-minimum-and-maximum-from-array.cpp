class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        // 1. Remove both from the left
        int case1 = right + 1;

        // 2. Remove both from the right
        int case2 = n - left;

        // 3. Remove left one from the left and right one from the right
        int case3 = (left + 1) + (n - right);

        return min({case1, case2, case3});
    }
};
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // Step 1: Get total number of distinct elements
        set<int> st(nums.begin(), nums.end());
        int totalDistinct = st.size();

        int n = nums.size();
        int i = 0, j = 0, count = 0;
        map<int, int> freq;

        while (j < n) {
            freq[nums[j]]++;  // include nums[j] in the window

            // Try shrinking window from left while it still contains all distinct elements
            while (freq.size() == totalDistinct) {
                // Since nums[i..j] is valid, so are all subarrays [i..j], [i+1..j], ..., [j..j]
                // So we add (n - j) subarrays that start from i and end from j to n-1
                count += (n - j);

                // Shrink from the left
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return count;
    }
};

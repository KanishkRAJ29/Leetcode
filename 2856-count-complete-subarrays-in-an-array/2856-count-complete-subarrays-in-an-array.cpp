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
            freq[nums[j]]++; 
            while (freq.size() == totalDistinct) {
                count += (n - j);
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

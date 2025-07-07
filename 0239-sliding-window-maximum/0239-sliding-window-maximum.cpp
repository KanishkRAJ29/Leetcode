class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> freq;  // Sorted map: keys are values, values are frequencies
        int maxe = INT_MIN;
        
        // Initialize first window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            maxe = max(maxe, nums[i]);
        }
        
        vector<int> ans;
        ans.push_back(maxe);
        
        int i = 0;
        int j = k;
        
        while (j < nums.size()) {
            // Remove nums[i] from window
            freq[nums[i]]--;
            if (freq[nums[i]] == 0) {
                freq.erase(nums[i]);
            }
            i++;
            
            // Add nums[j] to window
            freq[nums[j]]++;
            
            // maxe is always the last element in map (since map is sorted by key)
            maxe = freq.rbegin()->first;
            ans.push_back(maxe);
            j++;
        }
        
        return ans;
    }
};

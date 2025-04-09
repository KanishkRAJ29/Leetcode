class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size() == 0) return -1; 
        sort(nums.begin(), nums.end());

        if(nums[0] < k) return -1;

        int last = 0;
        int count = 0;

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] < k) return -1;
            if(last != nums[i] && nums[i] > k) count++;
            last = nums[i];  // Update last
        }

        return count;
    }
};



class Solution {
public:
    int solve2(vector<int>& nums, int start, int mid, int end) {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= start; --i) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
        
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= end; ++i) {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }
        
        return left_sum + right_sum;
    }
    
    int solve(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start]; // Base case: Single element
        }
        
        int mid = start + (end - start) / 2;
        
        // Recursively find maximum subarray sums in left and right halves
        int left_sum = solve(nums, start, mid);
        int right_sum = solve(nums, mid + 1, end);
        
        // Find maximum subarray sum crossing the midpoint
        int cross_sum = solve2(nums, start, mid, end);
        
        // Return the maximum of the three sums
        return max({left_sum, right_sum, cross_sum});
    }
    
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
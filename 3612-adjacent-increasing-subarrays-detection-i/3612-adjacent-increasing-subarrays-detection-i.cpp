// class Solution {
// public:
// // In - efficient : O(nk) tc, O(1) sc
//     bool hasIncreasingSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int l = 0;
//         int r = l + k;
//         bool inc1 = true;
//         bool inc2 = true;
//         while (r + k - 1 < n){
//             for(int i = 0; i < k-1 ; i++){
//                 if(nums[l+i] < nums[l+i+1] && inc1 == true){
//                     inc1 = true;
//                 }
//                 else{
//                     inc1 = false;
//                     break;
//                 }
//                 if(nums[r+i] < nums[r+i+1] && inc2 == true){
//                     inc2 = true;
//                 }
//                 else{
//                     inc2 = false;
//                     break;
//                 }
//             }
            
//             if(inc1 == true && inc2 == true){
//                 return true;
//             }
//             // if not got out answer, continue forward:
//             l++; 
//             r++;
//             // reset for next iteration
//             inc1 = true; inc2 = true;
//         }
//         return false;
//     }
// };

// MOST OPTIMAL : O(1) SC, O(N) TC
class Solution {
public:
    static bool hasIncreasingSubarrays(const std::vector<int>& nums, int k) {
        const int n = nums.size();
        if (n < 2 * k) return false;  // Not enough elements for two adjacent subarrays of size k

        int currentLength = 1;
        int previousLength = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++currentLength;
            } else {
                previousLength = currentLength;
                currentLength = 1;
            }

            // Check for two adjacent increasing subarrays of length k
            int possibleLength = max(currentLength / 2,min(currentLength, previousLength));
            if (possibleLength >= k) {
                return true;
            }
        }

        return false;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
 /*      stack<int>s;
       vector<int>result;
       int n=nums.size();
       k=k%n;
       for(int i=n-1;i>k;i--) {
        s.push(nums[i]);
       }
       while(!s.empty()){
        result.push_back(s.top());
        s.pop();
       }
       for(int i=0;i<n-k;i++){
        result.push_back(nums[i]);
       }
       for(int i=0;i<n;i++){
        nums[i]=result[i];
       }
*/


        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());

    }
};
class Solution {
public:
    int n;
    int solve(int start,int end,vector<int>&nums){
        vector<int> t(end-start+1+1,0);

        t[0]=0;
        t[1]=nums[start];
        for(int i=2;i<=end-start+1;i++){
            int take=nums[start+i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(take,skip);
        }
        return t.back();
    }
    int rob(vector<int>& nums) {
         n = nums.size();
        if (n == 1) return nums[0]; // Edge case: only one house
        
        // Create memoization table and initialize to -1
        
        

        
        int caseo=solve(0,n-2,nums);
        
        int caset=solve(1,n-1,nums);
        return max(caseo,caset);
    }
};

/*class Solution {
public:
    int solve(vector<int>& nums, int memo[101][2], int i, int last) {
        int n = nums.size();
        if (i >= n) return 0; // Base case: no houses left
        
        if (memo[i][last] != -1) return memo[i][last]; // Check memoization
        
        int taken = 0, notTaken = 0;

        if (i == 0) {
            // At the first house, we can rob or skip
            taken = nums[i] + solve(nums, memo, i + 2, 0);
            notTaken = solve(nums, memo, i + 1, 1);
        } 
        else if (i == n - 1) {
            // At the last house, only rob if the first house is not robbed
            if (last == 1) taken = nums[i] + solve(nums, memo, i + 2, last);
            notTaken = solve(nums, memo, i + 1, last);
        } 
        else {
            // For other houses, consider both options
            taken = nums[i] + solve(nums, memo, i + 2, last);
            notTaken = solve(nums, memo, i + 1, last);
        }

        return memo[i][last] = max(taken, notTaken);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Edge case: only one house
        
        // Create memoization table and initialize to -1
        int memo[101][2];
        memset(memo, -1, sizeof(memo));
        
        // Solve the problem starting from the first house and allowing circular constraint
        return solve(nums, memo, 0, 1);
    }
};
*/
class Solution {
public:
    
/*
    int solve(int i, int j, vector<vector<int>>& grid) {
        // Base case: bottom-right corner
        if (i == grid.size() - 1 && j == grid[0].size() - 1) 
            return grid[i][j];

        // Boundary check: if out of bounds, return a large value
        if (i >= grid.size() || j >= grid[0].size()) 
            return INT_MAX;

        // Memoization: if already computed, return the stored value
        if (dp[i][j] != -1) 
            return dp[i][j];

        // Recursive calls for down and right paths
        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);

        // Store and return the minimum path sum for the current cell
        dp[i][j] = grid[i][j] + min(down, right);
        return dp[i][j];
    }
*/
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0)); // Initialize dp array with -1
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
         for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        }

        // Fill last row (from right to left)
        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

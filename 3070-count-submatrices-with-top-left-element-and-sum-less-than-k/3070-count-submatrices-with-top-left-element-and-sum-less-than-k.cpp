class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        
        // Prefix sum matrix
        vector<vector<long long>> pref(m + 1, vector<long long>(n + 1, 0));
        
        int ans = 0;
        
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                pref[i][j] = grid[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
                
                if (pref[i][j] <= k) 
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
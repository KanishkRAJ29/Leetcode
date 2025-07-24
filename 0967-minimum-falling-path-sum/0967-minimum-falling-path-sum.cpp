int dp[101][101];
int n;

int find(int x, int y, vector<vector<int>>& g)
{   if(y<0||y>=g[0].size())return INT_MAX;
    if(x == n)
        return 0;

    if(dp[x][y] != -101)
        return dp[x][y];

    int ans = g[x][y] + find(x+1, y, g);

    return dp[x][y] = g[x][y]+min({find(x+1, y+1, g),find(x+1, y-1, g),find(x+1, y, g)});
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        n = mat.size();
        int ans = 1e9;
        
        for(int i=0; i<101; ++i)
            for(int j=0; j<101; ++j)
                dp[i][j] = -101;

        for(int i=0; i<mat.size(); ++i)
            ans = min(ans, find(0, i, mat));
        
        return ans;
    }
};
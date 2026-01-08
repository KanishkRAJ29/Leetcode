class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    const int NEG_INF = -1e9;

    int dfs(int i, int j, vector<int>& a, vector<int>& b) {
        if (i == n || j == m) return NEG_INF;
        if (dp[i][j] != NEG_INF) return dp[i][j];

        int take = a[i] * b[j];
        int take_more = take + max(0, dfs(i+1, j+1, a, b));

        int skip_a = dfs(i+1, j, a, b);
        int skip_b = dfs(i, j+1, a, b);

        return dp[i][j] = max({take_more, skip_a, skip_b});
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();
        dp.assign(n, vector<int>(m, NEG_INF));
        return dfs(0, 0, a, b);
    }
};
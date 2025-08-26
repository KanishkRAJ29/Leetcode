class Solution {
public:
    int n, m, target;
    // dp[i][sum] = best answer from row i..n-1 if current sum is `sum`
    // Max sum ≤ 70*70 = 4900
    static const int MAXS = 4900;
    vector<vector<int>> dp;

    int solve(int i, int sum, vector<vector<int>>& mat) {
        if (i == n) return abs(target - sum);
        int &res = dp[i][sum];
        if (res != -1) return res;

        res = INT_MAX;
        // choose exactly one element from row i
        for (int v : mat[i]) {
            int cand = solve(i + 1, sum + v, mat);
            if (cand < res) res = cand;
            if (res == 0) break; // optimal; prune
        }
        return res;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int T) {
        target = T;
        n = (int)mat.size();
        m = (int)mat[0].size();
        dp.assign(n, vector<int>(MAXS + 1, -1));

        return solve(0, 0, mat);
    }
};

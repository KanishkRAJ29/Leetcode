class Solution {
public:
    vector<vector<int>> dp;
    vector<int> newCuts;

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        newCuts.resize(m + 2);

        // Add 0 and n as the start and end of the stick
        for (int i = 0; i < m; i++) {
            newCuts[i + 1] = cuts[i];
        }
        newCuts[0] = 0;
        newCuts[m + 1] = n;
        sort(newCuts.begin(), newCuts.end());

        dp.resize(m + 2, vector<int>(m + 2, 0));

        for (int i = m+1; i >= 0; i--) {
            for (int j = i+2; j <= m+1; j++) {
                int ans = INT_MAX;

                for (int mid = i+1; mid <j; mid++) {
                    int currentCost = dp[i][mid] + dp[mid][j] + newCuts[j] - newCuts[i];
                    ans = min(ans, currentCost);
                }

                dp[i][j] = (i > j) ? 0 : ans;
            }
        }

        return dp[0][m+1];
    }
};
/*
class Solution {
public:
    vector<vector<int>> memo;
    vector<int> newCuts;

    int cost(int left, int right) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (right - left == 1) {
            return 0;
        }

        int ans = INT_MAX;
        for (int mid = left + 1; mid < right; mid++) {
            int currentCost = cost(left, mid) + cost(mid, right) +
newCuts[right] - newCuts[left]; ans = min(ans, currentCost);
        }

        memo[left][right] = ans;
        return ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        newCuts.resize(m + 2);

        // Copy cuts to newCuts with padding for 0 and n
        for (int i = 0; i < m; i++) {
            newCuts[i + 1] = cuts[i];
        }
        newCuts[m + 1] = n;
        sort(newCuts.begin(), newCuts.end());

        // Initialize memo table
        memo.resize(m + 2, vector<int>(m + 2, -1));

        // Start the recursive solution
        return cost(0, m + 1);
    }
};
*/
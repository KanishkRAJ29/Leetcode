class Solution {
public:
    unordered_map<int, int> stoneIndex;  // Map from stone value to index

    bool solve(vector<int>& stones, int ind, int lastj, vector<vector<int>>& dp) {
        if (ind == stones.size() - 1) return true;

        if (dp[ind][lastj] != -1) return dp[ind][lastj];

        for (int jump = lastj - 1; jump <= lastj + 1; ++jump) {
            if (jump > 0) {
                int nextStone = stones[ind] + jump;
                if (stoneIndex.count(nextStone)) {
                    int nextInd = stoneIndex[nextStone];
                    if (solve(stones, nextInd, jump, dp))
                        return dp[ind][lastj] = true;
                }
            }
        }
        return dp[ind][lastj] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; ++i) {
            stoneIndex[stones[i]] = i;
        }

        // dp[i][j]: Can we reach end from stone i with last jump j
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0, dp);
    }
};

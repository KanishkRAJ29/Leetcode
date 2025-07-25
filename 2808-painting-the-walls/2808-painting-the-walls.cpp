class Solution {
public:
    int solve(int i, int wallsLeft, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if (wallsLeft <= 0) return 0;
        if (i == cost.size()) return 1e9;  // Impossible

        if (dp[i][wallsLeft] != -1) return dp[i][wallsLeft];

        // Option 1: Paint wall i yourself
        int paint = cost[i] + solve(i + 1, wallsLeft - 1 - time[i], cost, time, dp);

        // Option 2: Skip (someone else paints)
        int skip = solve(i + 1, wallsLeft, cost, time, dp);

        return dp[i][wallsLeft] = min(paint, skip);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n, cost, time, dp);
    }
};

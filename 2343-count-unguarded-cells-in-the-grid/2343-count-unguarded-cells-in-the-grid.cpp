class Solution {
public:
    int moveL(vector<vector<int>>& vis, int row, int col) {
        int ans = 0;
        col--; // start from immediate left
        while (col >= 0 && vis[row][col] != 1) { // stop at guard/wall (1)
            if (vis[row][col] == 0) {            // only count if not seen before
                vis[row][col] = 2;               // mark as seen
                ans++;
            }
            col--;
        }
        return ans;
    }
    int moveR(vector<vector<int>>& vis, int row, int col) {
        int ans = 0;
        col++;
        int cols = vis[0].size();
        while (col < cols && vis[row][col] != 1) {
            if (vis[row][col] == 0) {
                vis[row][col] = 2;
                ans++;
            }
            col++;
        }
        return ans;
    }
    int moveU(vector<vector<int>>& vis, int row, int col) {
        int ans = 0;
        row--;
        while (row >= 0 && vis[row][col] != 1) {
            if (vis[row][col] == 0) {
                vis[row][col] = 2;
                ans++;
            }
            row--;
        }
        return ans;
    }
    int moveD(vector<vector<int>>& vis, int row, int col) {
        int ans = 0;
        row++;
        int rows = vis.size();
        while (row < rows && vis[row][col] != 1) {
            if (vis[row][col] == 0) {
                vis[row][col] = 2;
                ans++;
            }
            row++;
        }
        return ans;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        // mark guards and walls as blocked (1) and count them
        for (auto &g : guards) {
            vis[g[0]][g[1]] = 1;
            count++;
        }
        for (auto &w : walls) {
            if (vis[w[0]][w[1]] == 0) { // if not already a guard
                vis[w[0]][w[1]] = 1;
                count++;
            }
        }

        // For each guard, scan four directions and mark seen cells (2)
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            count += moveL(vis, r, c);
            count += moveR(vis, r, c);
            count += moveU(vis, r, c);
            count += moveD(vis, r, c);
        }

        return m * n - count;
    }
};

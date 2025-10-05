#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    void dfs(int r, int c,
             const vector<vector<int>>& h,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;
        static int dr[4] = {-1, 0, 1, 0};
        static int dc[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (vis[nr][nc]) continue;
            // Reverse flow: can go from (r,c) to (nr,nc) if next height >= current
            if (h[nr][nc] >= h[r][c]) dfs(nr, nc, h, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = (int)heights.size();
        if (m == 0) return {};
        n = (int)heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        // Pacific borders: top row & left column
        for (int c = 0; c < n; ++c) if (!pac[0][c]) dfs(0, c, heights, pac);
        for (int r = 0; r < m; ++r) if (!pac[r][0]) dfs(r, 0, heights, pac);

        // Atlantic borders: bottom row & right column
        for (int c = 0; c < n; ++c) if (!atl[m-1][c]) dfs(m-1, c, heights, atl);
        for (int r = 0; r < m; ++r) if (!atl[r][n-1]) dfs(r, n-1, heights, atl);

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
        return ans;
    }
};

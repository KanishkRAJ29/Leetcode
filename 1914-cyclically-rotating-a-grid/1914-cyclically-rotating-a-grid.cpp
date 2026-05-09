
class Solution {
public:
    
    void traverseNthLayer(int layer,
        vector<pair<int,int>>& cells,
    vector<vector<int>>& grid) {

        int top = layer;
        int left = layer;
        int bottom = grid.size() - layer - 1;
        int right = grid[0].size() - layer - 1;

        // top row
        for(int j = left; j <= right; j++) {
            cells.push_back({top, j});
        }

        // right column
        for(int i = top + 1; i <= bottom; i++) {
            cells.push_back({i, right});
        }

        // bottom row
        for(int j = right - 1; j >= left; j--) {
            cells.push_back({bottom, j});
        }

        // left column
        for(int i = bottom - 1; i > top; i--) {
            cells.push_back({i, left});
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans = grid;

        int numOfLayers = min(m, n) / 2;

        for(int layer = 0; layer < numOfLayers; layer++) {

            vector<pair<int,int>> cells;

            traverseNthLayer(layer, cells, grid);

            int len = cells.size();

            int rot = k % len;

            vector<int> values;

            for(auto &p : cells) {
                values.push_back(grid[p.first][p.second]);
            }

            // rotate anti-clockwise
            for(int i = 0; i < len; i++) {

                int newIndex = (i - rot + len) % len;

                int r = cells[newIndex].first;
                int c = cells[newIndex].second;

                ans[r][c] = values[i];
            }
        }

        return ans;
    }
};


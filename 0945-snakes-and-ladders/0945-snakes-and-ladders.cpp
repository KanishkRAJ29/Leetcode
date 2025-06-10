class Solution {
public:
    int n;

    pair<int, int> getCord(int s) {
        int row = (s - 1) / n;
        int col = (s - 1) % n;
        if (row % 2 == 1) col = n - 1 - col; // reverse direction for alternate rows
        row = n - 1 - row; // flip vertically to match board layout
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);

        int steps = 0;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front();
                q.pop();

                if (x == n * n) return steps;

                for (int i = 1; i <= 6; ++i) {
                    if (x + i > n * n) break;

                    pair<int, int> p = getCord(x + i);
                    int r = p.first;
                    int c = p.second;

                    if (visited[r][c]) continue;
                    visited[r][c] = true;

                    if (board[r][c] == -1) {
                        q.push(x + i);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

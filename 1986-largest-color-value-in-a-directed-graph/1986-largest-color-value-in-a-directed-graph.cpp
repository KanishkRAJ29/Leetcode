class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(n, 0);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;  // Initialize color count for source nodes
            }
        }

        int answer = 0, count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            count++;

            for (int i = 0; i < 26; i++) {
                answer = max(answer, dp[u][i]);
            }

            for (int &v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    int extra = (colors[v] - 'a' == i) ? 1 : 0;
                    dp[v][i] = max(dp[v][i], dp[u][i] + extra);
                }
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        if (count < n) return -1; // cycle exists
        return answer;
    }
};

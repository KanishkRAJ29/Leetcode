class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int qpow(long long x, int y) {
        long long res = 1;
        while (y) {
            if (y & 1) res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

    void dfs(unordered_map<int, vector<int>>& adj,
             int node,
             int parent,
             int depth,
             int& maxDep) {

        maxDep = max(maxDep, depth);

        for (int nxt : adj[node]) {
            if (nxt != parent) {
                dfs(adj, nxt, node, depth + 1, maxDep);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        if (n == 1) return 0;

        unordered_map<int, vector<int>> adj;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDep = 0;
        dfs(adj, 1, 0, 0, maxDep);

        return qpow(2, maxDep - 1);
    }
};
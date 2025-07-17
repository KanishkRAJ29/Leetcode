class Solution {
public:
    bool dfs(vector<int>& colArr, vector<vector<int>>& graph, bool col, int node) {
        colArr[node] = col;
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            if (colArr[neighbor] == -1) {
                if (!dfs(colArr, graph, !col, neighbor)) return false;
            } else if (colArr[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colArr(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (colArr[i] == -1) {
                if (!dfs(colArr, graph, 0, i)) return false;
            }
        }
        return true;
    }
};

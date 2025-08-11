class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int findParent(int x) {
        if (p[x] != x)
            p[x] = findParent(p[x]); // path compression
        return p[x];
    }

    void Union(int a, int b) {
        int x = findParent(a);
        int y = findParent(b);
        if (x == y) return;
        if (r[x] > r[y]) {
            p[y] = x;
        } else if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            r[x]++;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU d(edges.size());
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(d.findParent(v-1)==d.findParent(u-1)){
                while(ans.size()!=0)ans.pop_back();
                ans.push_back(u);
                ans.push_back(v);
            }else{
                d.Union(u-1,v-1);
            }
        }
        return ans;
    }
};/*class Solution {
public:
    bool dfs(int node, int parent, unordered_map<int, vector<int>>& adj, vector<int>& vis, int removethisedge, vector<vector<int>>& edges) {
        vis[node] = 1;

        for (int neighbor : adj[node]) {
            // Skip the removed edge
            if ((node == edges[removethisedge][0] && neighbor == edges[removethisedge][1]) ||
                (node == edges[removethisedge][1] && neighbor == edges[removethisedge][0])) {
                continue;
            }

            if (!vis[neighbor]) {
                if (dfs(neighbor, node, adj, vis, removethisedge, edges)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true; // Found a cycle
            }
        }
        return false;
    }

    bool findCycle(int removethisedge, unordered_map<int, vector<int>>& adj, vector<vector<int>>& edges, vector<int>& vis) {
        vis.assign(edges.size() + 1, 0);  // Reset visit array

        for (int i = 1; i <= edges.size(); i++) {
            if (!vis[i] && adj.count(i)) { // If not visited and exists in adjacency list
                if (dfs(i, -1, adj, vis, removethisedge, edges)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> nums = edges;
        std::sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Compare the second elements
        });

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);  // Since it's an undirected graph
        }

        int prev = nums[0][1];
        int number = 0;
        for (int i = 1; i < edges.size(); i++) {
            if (prev == nums[i][1]) number = prev;
            else prev = nums[i][1];
        }

        int index = 0;
        for (int i = 0; i<edges.size(); i++) {
            if (edges[i][1] == number) {
                index = i;
                break;
            }
        }

        for (int i = index + 1; i < edges.size(); i++) {
            vector<int> vis(edges.size() + 1, 0);
            if (!findCycle(i, adj, edges, vis)) index = i;
        }

        return edges[index];
    }
};
*//*class Solution {
private:
    int cycleStart = -1;

    // Peform the DFS and store a node in the cycle as cycleStart.
    void DFS(int src, vector<bool> &visited, vector<int> adjList[],
             vector<int> &parent) {
        visited[src] = true;

        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                DFS(adj, visited, adjList, parent);
                // If the node is visited and the parent is different then the
                // node is part of the cycle.
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int N = edges.size();

        vector<bool> visited(N, false);
        vector<int> parent(N, -1);

        vector<int> adjList[N];
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        DFS(0, visited, adjList, parent);

        unordered_map<int, int> cycleNodes;
        int node = cycleStart;
        // Start from the cycleStart node and backtrack to get all the nodes in
        // the cycle. Mark them all in the map.
        do {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes[edges[i][0] - 1] && cycleNodes[edges[i][1] - 1]) {
                return edges[i];
            }
        }

        return {};
    }
};*/

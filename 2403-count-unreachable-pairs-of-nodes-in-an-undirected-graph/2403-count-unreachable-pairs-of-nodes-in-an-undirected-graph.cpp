class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if (x_p == y_p) return;
        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        }
        else if (rank[y_p] > rank[x_p]) {
            parent[x_p] = y_p;
        }
        else {
            parent[x_p] = y_p;
            rank[y_p]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initialize the parent of each node to itself.
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Use the correct number of edges.
        for (int i = 0; i < edges.size(); i++){
            unionSet(edges[i][0], edges[i][1]);
        }
        
        // Count the size of each connected component.
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++){
            freq[find(i)]++;  // Use find(i) to ensure correct component representative.
        }
        
        long long ans = 0;
        int total = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            total += it->second;
            ans += static_cast<long long>(it->second) * (n - total);
        }
        
        return ans;
    }
};

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        // dist1[i] = distance from node1 to i (or INT_MAX if unreachable)
        // dist2[i] = distance from node2 to i (or INT_MAX if unreachable)
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        
        // Helper to fill dist[] by walking the functional graph
        auto fillDist = [&](int start, vector<int>& dist) {
            int d = 0, u = start;
            while (u != -1 && dist[u] == INT_MAX) {
                dist[u] = d++;
                u = edges[u];
            }
        };
        
        fillDist(node1, dist1);
        fillDist(node2, dist2);
        
        int answer = -1;
        int bestMaxDist = INT_MAX;
        // Check every node i as a candidate
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;
            int m = max(dist1[i], dist2[i]);
            // minimize the maximum of the two distances
            if (m < bestMaxDist || (m == bestMaxDist && i < answer)) {
                bestMaxDist = m;
                answer = i;
            }
        }
        
        return answer;
    }
};

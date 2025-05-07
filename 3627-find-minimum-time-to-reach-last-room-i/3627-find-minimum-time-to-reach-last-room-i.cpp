#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    static constexpr int DIRS[4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    
    int minTimeToReach(vector<vector<int>>& m) {
        int n = m.size();
        if (n == 0 || m[0].empty() || m[0][0] == -1)
            return -1;
        int mcols = m[0].size();

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(n, vector<long long>(mcols, INF));
        
        // Min‐heap of (time, row, col)
        using State = tuple<long long,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at (0,0) at t = 0
        dist[0][0] = 0;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            
            // If we've found a better way already, skip
            if (t > dist[i][j]) continue;
            
            // Once we reach target, we can return immediately
            if (i == n-1 && j == mcols-1)
                return int(t);

            // Relax all four neighbors
            for (auto &d : DIRS) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= mcols) 
                    continue;
                if (m[ni][nj] == -1) 
                    continue;

                // Compute waiting time if we arrive too early
                long long wait = max(0LL, (long long)m[ni][nj] - t);
                long long nt = t + 1 + wait;  // step cost + wait

                if (nt < dist[ni][nj]) {
                    dist[ni][nj] = nt;
                    pq.emplace(nt, ni, nj);
                }
            }
        }

        // If target never reached
        return -1;
    }
};

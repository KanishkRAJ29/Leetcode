

class Solution {
public:
    // count walls in integer closed interval [L, R]
    static int countRange(const vector<int>& W, long long L, long long R) {
        if (L > R) return 0;
        auto itL = lower_bound(W.begin(), W.end(), (int)L);
        auto itR = upper_bound(W.begin(), W.end(), (int)R);
        return (int)(itR - itL);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = (int)robots.size();
        int m = (int)walls.size();

        // sort robots by position, keep distances aligned
        vector<pair<int,int>> rd(n);
        for (int i = 0; i < n; ++i) rd[i] = {robots[i], distance[i]};
        sort(rd.begin(), rd.end());
        vector<int> r(n), d(n);
        for (int i = 0; i < n; ++i) { r[i] = rd[i].first; d[i] = rd[i].second; }

        sort(walls.begin(), walls.end());

        // self[i] = 1 if a wall at robot position r[i]
        vector<int> self(n, 0);
        for (int i = 0; i < n; ++i) {
            self[i] = binary_search(walls.begin(), walls.end(), r[i]) ? 1 : 0;
        }

        // per-gap counts
        int gaps = max(0, n - 1);
        vector<int> A(gaps, 0), B(gaps, 0), C(gaps, 0);
        for (int i = 0; i < gaps; ++i) {
            // robot i shoots RIGHT into gap i: [r[i]+1, min(r[i]+d[i], r[i+1]-1)]
            long long R1 = min(1LL * r[i] + d[i], 1LL * r[i+1] - 1);
            long long L1 = 1LL * r[i] + 1;
            int Ai = countRange(walls, L1, R1);

            // robot i+1 shoots LEFT into gap i: [max(r[i]+1, r[i+1]-d[i+1]), r[i+1]-1]
            long long L2 = max(1LL * r[i] + 1, 1LL * r[i+1] - d[i+1]);
            long long R2 = 1LL * r[i+1] - 1;
            int Bi = countRange(walls, L2, R2);

            // overlap (if any): [max(L1, L2), min(R1, R2)]
            long long Lo = max(L1, L2);
            long long Hi = min(R1, R2);
            int Ov = countRange(walls, Lo, Hi);

            A[i] = Ai;
            B[i] = Bi;
            C[i] = Ai + Bi - Ov; // union
        }

        // exteriors
        int leftExt  = 0; // walls in [r0 - d0, r0 - 1]
        int rightExt = 0; // walls in [r_{n-1} + 1, r_{n-1} + d_{n-1}]
        if (n >= 1) {
            leftExt = countRange(walls, 1LL * r[0] - d[0], 1LL * r[0] - 1);
            rightExt = countRange(walls, 1LL * r[n-1] + 1, 1LL * r[n-1] + d[n-1]);
        }

        // DP over actions {N=0, L=1, R=2}
        const int Nact = 3;
        vector<long long> dp_prev(Nact, LLONG_MIN), dp_cur(Nact, LLONG_MIN);

        auto setmax = [](long long &a, long long b){ if (b > a) a = b; };

        if (n == 0) return 0; // no robots

        // base i = 0
        // If robot 0: N -> 0, L -> self[0] + left exterior, R -> self[0] (gap 0 contribution comes later)
        dp_prev[0] = 0;                          // N
        dp_prev[1] = self[0] + leftExt;         // L
        dp_prev[2] = self[0];                   // R

        // transition helper for gap (i-1)
        auto f = [&](int i_minus_1, int a_prev, int a_cur)->int {
            // using A[i-1], B[i-1], C[i-1]
            if (a_prev == 2 && a_cur == 1) return C[i_minus_1];  // R then L -> both in gap
            if (a_prev == 2 && a_cur != 1) return A[i_minus_1];  // only left robot shoots right
            if (a_prev != 2 && a_cur == 1) return B[i_minus_1];  // only right robot shoots left
            return 0;                                            // none
        };

        for (int i = 1; i < n; ++i) {
            fill(dp_cur.begin(), dp_cur.end(), LLONG_MIN);
            for (int a_cur = 0; a_cur < Nact; ++a_cur) {
                long long addSelf = (a_cur == 0 ? 0 : self[i]);
                for (int a_prev = 0; a_prev < Nact; ++a_prev) {
                    if (dp_prev[a_prev] == LLONG_MIN) continue;
                    long long cand = dp_prev[a_prev] + f(i - 1, a_prev, a_cur) + addSelf;
                    setmax(dp_cur[a_cur], cand);
                }
            }
            dp_prev.swap(dp_cur);
        }

        // add right exterior if last robot shoots RIGHT
        long long ans = max({ dp_prev[0], dp_prev[1], dp_prev[2] + (long long)rightExt });
        return (int)ans;
    }
};

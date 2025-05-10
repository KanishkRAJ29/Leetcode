#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9+7;

long long modexp(long long a, long long e=MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<int> cnt(10, 0);
        int S = 0;
        for (char c : num) {
            int d = c - '0';
            cnt[d]++;
            S += d;
        }
        // total sum must be even
        if (S & 1) return 0;
        int half = S / 2;
        int n_even = (n + 1) / 2;
        int n_odd  = n / 2;

        // precompute factorials up to n
        vector<long long> fact(n+1, 1);
        for (int i = 1; i <= n; i++) 
            fact[i] = fact[i-1] * i % MOD;

        // dp[i][s] = number of ways (∏ C(cnt[k], t_k)) 
        // to pick exactly i items into the even slots summing to s
        vector<vector<long long>> dp(n_even+1, vector<long long>(half+1, 0));
        dp[0][0] = 1;

        // transition digit by digit
        for (int d = 0; d <= 9; d++) {
            int c = cnt[d];
            if (c == 0) continue;  // no change
            // precompute C(c, t) for t=0..c
            vector<long long> Cc(c+1, 1);
            for (int t = 0; t <= c; t++) {
                // C(c, t) = fact[c] / (fact[t]*fact[c-t])
                Cc[t] = fact[c] 
                      * modexp(fact[t] * fact[c-t] % MOD) 
                      % MOD;
            }
            // build next layer
            vector<vector<long long>> ndp(n_even+1, vector<long long>(half+1, 0));
            for (int i = 0; i <= n_even; i++) {
                for (int s = 0; s <= half; s++) {
                    long long ways = dp[i][s];
                    if (!ways) continue;
                    // assign t of digit d into even‑slots
                    for (int t = 0; t <= c && i + t <= n_even && s + d*t <= half; t++) {
                        ndp[i + t][s + d*t] = (ndp[i + t][s + d*t]
                                             + ways * Cc[t]) % MOD;
                    }
                }
            }
            dp.swap(ndp);
        }

        long long chooseWays = dp[n_even][half];
        if (!chooseWays) 
            return 0;

        // multiply by permutations within even/odd positions
        // and divide by identical‑digit overcount
        long long ans = chooseWays
                      * fact[n_even] % MOD
                      * fact[n_odd]  % MOD;

        // denominator = ∏ fact[cnt[d]]
        long long denom = 1;
        for (int d = 0; d < 10; d++) 
            denom = denom * fact[cnt[d]] % MOD;

        ans = ans * modexp(denom) % MOD;
        return (int)ans;
    }
};

class Solution {
public:
    // dp[i][pi][par] = best length from index i,
    //   where pi = 0 means prev==-1, 1 means prev==0, 2 means prev==1,
    //   par = targetParity (0=even sums,1=odd sums).
    vector< array< array<int,2>, 3 > > dp;
    vector<int> A;
    int n;

    int solve(int i, int prev, int len, int parity) {
        int pi = (prev == -1 ? 0 : prev+1);  // map -1→0, 0→1, 1→2
        auto &cell = dp[i][pi][parity];
        if (cell != -1) return cell;

        if (i == n) {
            return cell = 0;
        }

        // 1) skip A[i]
        int best = solve(i+1, prev, len, parity);

        // 2) take A[i] if allowed
        if (prev == -1 || ((prev + A[i]) % 2) == parity) {
            // +1 for this pick, then recurse
            best = max(best, 1 + solve(i+1, A[i], len+1, parity));
        }

        return cell = best;
    }

    int maximumLength(vector<int>& nums) {
        n = nums.size();
        A = nums;
        // reduce to bits
        for (int &x : A) x &= 1;  

        // init dp to -1
        dp.assign(n+1, {});
        for (int i = 0; i <= n; i++)
            for (int pi = 0; pi < 3; pi++)
                for (int p = 0; p < 2; p++)
                    dp[i][pi][p] = -1;

        // try both parities
        int ansEven = solve(0, -1, 0, 0);
        int ansOdd  = solve(0, -1, 0, 1);
        return max(ansEven, ansOdd);
    }
};

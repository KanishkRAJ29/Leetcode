static const int MOD = 1e9+7;

// multiply two 26×26 matrices
vector<vector<long long>> matMul(
    const vector<vector<long long>>& A,
    const vector<vector<long long>>& B
) {
    vector<vector<long long>> C(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i) {
        for (int k = 0; k < 26; ++k) {
            if (!A[i][k]) continue;
            long long a = A[i][k];
            for (int j = 0; j < 26; ++j) {
                C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// fast‐power a 26×26 matrix
vector<vector<long long>> matPow(
    vector<vector<long long>> base,
    long long exp
) {
    vector<vector<long long>> result(26, vector<long long>(26, 0));
    // identity matrix
    for (int i = 0; i < 26; ++i) result[i][i] = 1;

    while (exp > 0) {
        if (exp & 1) result = matMul(result, base);
        base   = matMul(base, base);
        exp   >>= 1;
    }
    return result;
}

class Solution {
public:
    int lengthAfterTransformations(string s, long long t, vector<int>& nums) {
        // 1) Build initial freq vector f0
        vector<long long> f0(26, 0);
        for (char c : s) f0[c - 'a']++;

        // 2) Build transition matrix M
        vector<vector<long long>> M(26, vector<long long>(26, 0));
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < nums[j]; ++k) {
                int dest = (j + 1 + k) % 26;
                M[dest][j] = 1;
            }
        }

        // 3) Compute M^t
        auto Mt = matPow(M, t);

        // 4) Multiply Mt by f0 to get ft
        vector<long long> ft(26, 0);
        for (int i = 0; i < 26; ++i) {
            long long sum = 0;
            for (int j = 0; j < 26; ++j) {
                sum = (sum + Mt[i][j] * f0[j]) % MOD;
            }
            ft[i] = sum;
        }

        // 5) Sum up ft[i]
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + ft[i]) % MOD;
        }
        return (int)ans;
    }
};

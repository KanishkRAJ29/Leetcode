class Solution {
public:
   static const int MOD = 1e9 + 7;

int lengthAfterTransformations(const string& s, int t) {
    // 1) Use long long
    vector<long long> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    // 2) Each round, build nextFreq from freq, taking mod at every addition
    for (int step = 0; step < t; step++) {
        vector<long long> nextFreq(26, 0);
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0) continue;
            if (j != 25) {
                nextFreq[j + 1] = (nextFreq[j + 1] + freq[j]) % MOD;
            } else {
                // 'z' → 'a' + 'b'
                nextFreq[0] = (nextFreq[0] + freq[j]) % MOD;
                nextFreq[1] = (nextFreq[1] + freq[j]) % MOD;
            }
        }
        freq.swap(nextFreq);
    }

    // 3) Sum up, modding again
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = (ans + freq[i]) % MOD;
    }
    return (int)ans;
}

};
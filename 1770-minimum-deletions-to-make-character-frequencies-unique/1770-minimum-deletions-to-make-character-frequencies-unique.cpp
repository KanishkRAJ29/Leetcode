class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // keep only non-zero freqs
        vector<int> f;
        for (int x : freq) 
            if (x) f.push_back(x);

        sort(f.begin(), f.end(), greater<int>());

        int deletions = 0;
        // make each f[i] < f[i-1]
        for (int i = 1; i < f.size(); ++i) {
            if (f[i] >= f[i-1]) {
                int want = max(0, f[i-1] - 1);
                deletions += (f[i] - want);
                f[i] = want;
            }
        }
        return deletions;
    }
};

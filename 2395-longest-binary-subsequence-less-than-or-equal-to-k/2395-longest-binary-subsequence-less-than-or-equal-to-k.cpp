class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = floor(log2(k)+1);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
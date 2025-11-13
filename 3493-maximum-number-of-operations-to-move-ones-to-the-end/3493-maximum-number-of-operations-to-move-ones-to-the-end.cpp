class Solution {
public:
    int maxOperations(string s) {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else { // s[i] == '0'
                // if this zero is the last char or the next char is '1',
                // then this zero 'triggers' adding all previously seen ones.
                if (i + 1 == n || s[i + 1] == '1') ans += ones;
            }
        }
        return (int)ans;
    }
};

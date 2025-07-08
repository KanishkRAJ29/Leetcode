class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // 1) Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // 2) Optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3) Parse digits into a long long to detect overflow
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            int d = s[i] - '0';
            result = result * 10 + d;

            // 4) Clamp to 32‑bit signed range if we overflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return int(sign * result);
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += (char)('0' + (num % k));
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int len = 1;

        while (count < n) {
            // Generate palindromes of length `len`
            for (int half = pow(10, (len - 1) / 2); half < pow(10, (len + 1) / 2); ++half) {
                string left = to_string(half);
                string right = left;
                if (len % 2) right.pop_back();
                reverse(right.begin(), right.end());
                string full = left + right;
                long long num = stoll(full);

                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                    if (count == n) return sum;
                }
            }
            len++;
        }

        return sum;
    }
};

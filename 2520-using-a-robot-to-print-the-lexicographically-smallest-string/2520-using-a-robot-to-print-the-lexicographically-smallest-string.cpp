class Solution {
public:
    string robotWithString(string s) {
        stack<char> t;
        string p;
        int n = s.size();
        vector<char> minRight(n + 1, 'z' + 1);  // dummy extra space

        // Precompute min suffix from right
        for (int i = n - 1; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], s[i]);
        }

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // While stack top <= smallest remaining in s, pop and write to paper
            while (!t.empty() && t.top() <= minRight[i + 1]) {
                p += t.top();
                t.pop();
            }
        }

        // Flush remaining stack
        while (!t.empty()) {
            p += t.top();
            t.pop();
        }

        return p;
    }
};

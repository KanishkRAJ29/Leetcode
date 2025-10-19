#include <bits/stdc++.h>
using namespace std;

string opB(string s, int b) {
    int n = (int)s.size();
    if (n == 0) return s;
    b %= n;
    if (b == 0) return s;
    // rotate right by b
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + b);
    reverse(s.begin() + b, s.end());
    return s;
}

string opA(string s, int a) {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i % 2) {
            int c = s[i] - '0';
            c = (c + a) % 10;
            s[i] = char('0' + c);
        }
    }
    return s;
}

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;               // faster than set for visited
        string best = s;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur < best) best = cur;

            string s1 = opA(cur, a);
            if (!vis.count(s1)) {
                vis.insert(s1);
                q.push(s1);
            }

            string s2 = opB(cur, b);
            if (!vis.count(s2)) {
                vis.insert(s2);
                q.push(s2);
            }
        }
        return best;
    }
};

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for (int i = 0; i < s.size(); i += k) {
            string t = "";
            for (int j = i; j < i + k && j < s.size(); j++) {
                t += s[j];
            }
            while (t.size() < k) {
                t += fill;
            }
            res.push_back(t);
        }
        return res;
    }
};

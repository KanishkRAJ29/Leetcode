class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        if (rows == 1) return e;

        int columns = e.length() / rows;
        string s;

        for (int i = 0; i < columns; i++) {
            for (int j = i; j < e.length(); j += columns + 1) {
                s += e[j];
            }
        }

        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        return s;
    }
};
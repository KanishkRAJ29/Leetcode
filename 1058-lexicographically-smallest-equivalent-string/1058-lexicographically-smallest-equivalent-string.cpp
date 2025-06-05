class Solution {
public:
    vector<char> parent;
    vector<int> rank;

    // Find with path compression
    char find(char x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // Union with lexicographically smaller root
    void unionF(char x, char y) {
        char px = find(x);
        char py = find(y);
        if (px == py) return;

        if (px < py) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(128); // all ASCII chars
        for (int i = 0; i < 128; ++i) {
            parent[i] = i;
        }

        // Union the pairs from s1 and s2
        for (int i = 0; i < s1.size(); ++i) {
            unionF(s1[i], s2[i]);
        }

        // Build result
        string result = "";
        for (char ch : baseStr) {
            result += find(ch);
        }

        return result;
    }
};

class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int findParent(int x) {
        if (p[x] != x)
            p[x] = findParent(p[x]); // path compression
        return p[x];
    }

    void Union(int a, int b) {
        int x = findParent(a);
        int y = findParent(b);
        if (x == y) return;
        if (r[x] > r[y]) {
            p[y] = x;
        } else if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            r[x]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& e) {
        DSU eq(26);

        for(int i=0;i<e.size();i++){
            int u=e[i][0]-'a';
            int v=e[i][3]-'a';
            char c=e[i][1];
            if(c=='='){
                eq.Union(u,v);
            }
        }
        for(int i=0;i<e.size();i++){
            int u=e[i][0]-'a';
            int v=e[i][3]-'a';
            char c=e[i][1];
            if(c=='!'&&eq.findParent(u)==eq.findParent(v)){
                return false;
            }
        }
        return true;
    }
};
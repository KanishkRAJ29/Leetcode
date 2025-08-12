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
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()+1<n)return -1;
        DSU d(n);
        for(int i=0;i<c.size();i++){
            int u=c[i][0];
            int v=c[i][1];
            if(d.findParent(u)!=d.findParent(v)){
                d.Union(u,v);
            }
        }
        int totalGroups=0;
        for(int i=0;i<n;i++){
            if(d.findParent(i)==i)totalGroups++;
        }
       int  totalConnections=c.size();
        return totalGroups-1;
    }
};
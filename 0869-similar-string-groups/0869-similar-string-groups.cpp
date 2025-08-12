class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int findParent(int x) {
        if (p[x] != x) p[x] = findParent(p[x]);
        return p[x];
    }

    void Union(int a, int b) {
        int x = findParent(a);
        int y = findParent(b);
        if (x == y) return;
        if (r[x] > r[y]) p[y] = x;
        else if (r[x] < r[y]) p[x] = y;
        else { p[y] = x; r[x]++; }
    }
};


class Solution {
public:
    bool similar(string &a,string&b){
        int n=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]&&++n>2)return false;
            
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        DSU d(strs.size());
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(similar(strs[i],strs[j])){
                    d.Union(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<strs.size();i++){
            if(d.findParent(i)==i)count++;
        }
        return count;
    }
};

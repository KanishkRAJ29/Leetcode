class DSU{
    public:
    vector<int>p,r;
    DSU(int n):p(n),r(n,0){
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    bool unite(int a,int b){
        a=find(a);b=find(b);
        if(a==b)return false;
        if(r[a]<r[b])swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]++;
        return false;
    }
};

class Solution {
public:
    int cal(int time,vector<vector<int>>& edges,int n){
        vector<vector<int>>temp=edges;
        DSU dsu(n);
        for(int i=0;i<edges.size();i++){
            if(temp[i][2]>time){
                dsu.unite(temp[i][0],temp[i][1]);
            }
        }
        unordered_set<int>r;
        for(int i=0;i<n;i++){
            r.insert(dsu.find(i));
        }
        return (int)r.size();
    }
        int minTime(int n, vector<vector<int>>& edges, int k) {
        // 0) Quick check: if without removing anything we already have >=k components,
        //    then answer is 0.
        if (cal(0, edges, n) >= k) 
            return 0;

        // 1) gather and sort unique removal‐times
        vector<int> times;
        times.reserve(edges.size());
        for (auto &e : edges)
            times.push_back(e[2]);
        sort(times.begin(), times.end());
        times.erase(unique(times.begin(), times.end()), times.end());

        // 2) binary‐search over the times[]
        int low = 0, high = (int)times.size() - 1;
        int ans = times.back();  // default to the largest removal time
        while (low <= high) {
            int mid = (low + high) >> 1;
            int t   = times[mid];
            int comps = cal(t, edges, n);
            if (comps >= k) {
                ans = t;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

};
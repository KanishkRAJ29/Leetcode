
class DSU{
    public:
    vector<int>p,r;

    DSU(int n){
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            r[i]=0;
        }
    }

    int findParent(int& x){
        if(p[x]==x)return p[x];
        return findParent(p[x]);
    }
    void Union(int &a,int& b){
        int x=findParent(a);
        int y=findParent(b);
        if(x==y)return;
        else if(r[x]>r[y]){
            p[y]=x;
        }
        else if(r[x]<r[y]){
            p[x]=y;
        }else{
            p[y]=x;
            r[x]++;
        }
        return;
    }
};
class Solution {
public:
   
    int findCircleNum(vector<vector<int>>& c) {
        int numOFOnes=0;
        DSU d(c.size());
        for(int i=0;i<c.size();i++){
            for(int j=0;j<c[0].size();j++){
                if(c[i][j]==1){
                    
                    if(i!=j){
                        d.Union(i,j);
                    }
                }
            }
        }
int comp = 0;
for (int i = 0; i < c.size(); i++) {
    if (d.findParent(i) == i) // root node
        comp++;
}
return comp;

    }
};
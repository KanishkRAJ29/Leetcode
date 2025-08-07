class Solution {
public:
    void buildSeg(int i,vector<int>&baskets,int left,int right,vector<int>&st){
        if(left==right){
            st[i]=baskets[left];
            return;
        }
        int mid=left+(right-left)/2;
        buildSeg(2*i+1,baskets,left,mid,st);
        buildSeg(2*i+2,baskets,mid+1,right,st);
        st[i]=max(st[2*i+1],st[2*i+2]);
        
    }
    bool query(int i,int l,int r,vector<int>&st,int val){
        if(st[i]<val)return false;
        if(l==r){
            st[i]=-1;
            return true;
        }
        bool placed=false;
        int mid=l+(r-l)/2;
        if(st[2*i+1]>=val){
            placed=query(2*i+1,l,mid,st,val);
        }else{
            placed=query(2*i+2,mid+1,r,st,val);
        }
        st[i]=max(st[2*i+1],st[2*i+2]);

        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int>segmentTree(4*n,-1);
        buildSeg(0,baskets,0,baskets.size()-1,segmentTree);
        int unplaced=0;
        for(int &num:fruits){
            if(!query(0,0,n-1,segmentTree,num))unplaced++;
        }
        return unplaced;
    }
};
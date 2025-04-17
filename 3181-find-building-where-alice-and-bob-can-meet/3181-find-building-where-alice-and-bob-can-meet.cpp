class Solution {
public:
    vector<int>st;
    void buildSt(int l,int r,int i,vector<int>&heights){
        if(l==r){st[i]=l;
        return;}
        int mid=l+(r-l)/2;
        buildSt(l,mid,2*i+1,heights);
        buildSt(mid+1,r,2*i+2,heights);
        int leftidx=st[2*i+1];
        int rightidx=st[2*i+2];
        if(heights[leftidx]>=heights[rightidx]){
            st[i]=leftidx;
        }else{
            st[i]=rightidx;
        }
    }
    int rmqi(int l,int r,int s,int e,int i,vector<int>&heights){
        if(l>e||r<s){
            return -1;
        }
        if(l>=s&&r<=e){
            return st[i];
        }
        int mid=l+(r-l)/2;
        int lefti=rmqi(l,mid,s,e,2*i+1,heights);
        int righti=rmqi(mid+1,r,s,e,2*i+2,heights);
        if(lefti==-1)return righti;
        if(righti==-1)return lefti;
        if(heights[lefti]>=heights[righti]){
            return lefti;
        }else return righti;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        st.resize(4*n);
        vector<int>ans;
        buildSt(0,n-1,0,heights);
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int maxi=max(start,end);
            int mini=min(start,end);
            if(heights[maxi]>heights[mini]){
                ans.push_back(maxi);
                continue;
            }
            else if(start==end){
                ans.push_back(start);
                continue;
            }
            else{
                int j=maxi+1;
                int res=n-1;
                int flag=false;
                int e=n-1;
                while(j<=e){
                    int mid=j+(e-j)/2;
                    int idx = rmqi(0,n-1, j, mid, 0, heights);

                    if(heights[idx]>heights[start]&&heights[idx]>heights[end]){
                        res=min(res,idx);
                        e=mid-1;
                        flag=true;
                    }else{
                        j=mid+1;
                    }
                }
                if(!flag)ans.push_back(-1);
                else ans.push_back(res);
            }
        }
        return ans;

    }
};
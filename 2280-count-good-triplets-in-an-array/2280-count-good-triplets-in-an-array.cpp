class Solution {
public:
    int querySt(int l,int r,int i,int s,int end,vector<long long>&st){
        if(l>end||r<s)return 0;
        if(l>=s&&r<=end){
            return st[i];
        }
        int mid=l+(r-l)/2;
        int left=querySt(l,mid,2*i+1,s,end,st);
        int right=querySt(mid+1,r,2*i+2,s,end,st);
        return left+right;
    }
    void updateSt(int l,int r,int i,int index,vector<long long>&st){
        if(l==r){st[i]=1;
        return;}
        
        int mid=l+(r-l)/2;
        if(index<=mid){
            updateSt(l,mid,2*i+1,index,st);
        }else{
            updateSt(mid+1,r,2*i+2,index,st);
        }
        st[i]=st[2*i+1]+st[2*i+2];
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        int n=nums1.size();
        vector<long long>st(4*n,0);
        long long ans=0;
        updateSt(0,n-1,0,mp[nums1[0]],st);
        for(int i=1;i<n;i++){
            int idx=mp[nums1[i]];
            long long LeftCommonCount=querySt(0,n-1,0,0,idx,st);
            updateSt(0,n-1,0,idx,st);
            long long LeftUncommon=i-LeftCommonCount;
            long long elemAfterIdxNums2=n-1-idx;
            long long rightCommon=elemAfterIdxNums2-LeftUncommon;
            ans+=LeftCommonCount*rightCommon;
        }
        return ans;
    }
};
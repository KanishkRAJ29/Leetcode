class NumArray {
public:
    int n;
    vector<int>segmentTree;
    int sumST(int i,int start,int end,int l,int r){
        if(l>end||r<start)return 0;
        if(l>=start&&r<=end)return segmentTree[i];
        int mid=l+(r-l)/2;
        return sumST(2*i+1,start,end,l,mid)+sumST(2*i+2,start,end,mid+1,r);
    }
    void buildST(int i,int l,int r,vector<int>&nums){
        if(l==r){segmentTree[i]=nums[l];
        return ;}
        int mid=l+(r-l)/2;
        buildST(2*i+1,l,mid,nums);
        buildST(2*i+2,mid+1,r,nums);
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    void updateT(int index,int val,int i,int l,int r){
        if(l==r){
            segmentTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(index<=mid){
            updateT(index,val,2*i+1,l,mid);
        }else{
            updateT(index,val,2*i+2,mid+1,r);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree.resize(4*n);
        buildST(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateT(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return sumST(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
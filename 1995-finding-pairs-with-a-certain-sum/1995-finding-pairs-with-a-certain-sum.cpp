class FindSumPairs {
public:
    unordered_map<int,int>mp;
    vector<int>nums;
    vector<int>num;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums=nums1;
        num=nums2;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[num[index]]--;
        mp[num[index]+val]++;
        num[index]+=val;

    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            if(first<0)continue;
            int second=tot-first;
            if(mp.count(second)){
                ans+=mp[second];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
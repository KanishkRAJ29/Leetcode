class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        
        int n=nums.size();
        set<int>st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                for(int j=max(0,i-k);j<=i+k&&j<n;j++){
                    if(abs(i-j)<=k)st.insert(j);
                }
            }
        }
        vector<int>ans;
        for(int s:st){
            ans.push_back(s);
        }
    return ans;
    }
};
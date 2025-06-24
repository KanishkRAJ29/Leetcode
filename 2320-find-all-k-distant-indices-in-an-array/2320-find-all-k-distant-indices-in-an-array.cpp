class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        
        int n=nums.size();
        vector<int>ans;
        
        int mini=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int l=max(mini,i-k);
                mini=min(n-1,i+k)+1;

                for(int j=l;j<mini;j++){
                    if(abs(i-j)<=k)ans.push_back(j);
                }
            }
        }
        
    return ans;
    }
};
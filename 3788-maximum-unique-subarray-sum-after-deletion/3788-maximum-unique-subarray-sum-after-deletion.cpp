class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0&&st.find(nums[i])==st.end()){
                count+=nums[i];
                st.insert(nums[i]);
            }
        }
        if(st.size()==0)return *max_element(nums.begin(),nums.end());
        return count;
    }
};
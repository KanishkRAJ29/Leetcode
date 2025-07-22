class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int j=0,i=0;
        int sum=0;
        int ans=0;
        while(j<nums.size()){
            if(st.find(nums[j])==st.end()){st.insert(nums[j]);
            sum+=nums[j];
            ans=max(ans,sum);
            j++;}else{
                
                while(nums[i]!=nums[j]){
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};
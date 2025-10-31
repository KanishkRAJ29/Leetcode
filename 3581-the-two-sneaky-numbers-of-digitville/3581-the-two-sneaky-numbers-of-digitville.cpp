class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=count){
                ans.push_back(nums[i]);
                i++;

            }
            count++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>&temp,vector<int>&nums){
        if(temp.size()==nums.size()){ans.push_back(temp);
        return;}
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                solve(temp,nums);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<int>temp;
        solve(temp,nums);
        return ans;
    }
};
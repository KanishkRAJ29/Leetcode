class Solution {
public:
vector<vector<int>> result;
void solve(int i,vector<int>& candidates, int target,vector<int>temp){
    if(target==0){
        result.push_back(temp);
        return;
    }
    if(i>=candidates.size()|| target<0){
        return;
    }

   
    temp.push_back(candidates[i]);
    solve(i,candidates,target-candidates[i],temp);
  
    temp.pop_back();
    solve(i+1,candidates,target,temp);



}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0,candidates,target,temp);
        return result;
    }
};
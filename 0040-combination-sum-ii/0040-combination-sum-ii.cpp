class Solution {
public:
    void sum(vector<vector<int>>& result, vector<int>& temp,
             vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            sum(result, temp, candidates, target - candidates[i], i + 1);
           temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        sum(ans, temp, candidates, target, 0);
        return ans;
    }
};
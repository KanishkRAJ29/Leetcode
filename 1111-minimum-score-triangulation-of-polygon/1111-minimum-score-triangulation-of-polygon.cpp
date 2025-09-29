class Solution {
public:
    int solve(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if((j-i)<2) return 0;

        int mn=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        for(int k=i+1; k<j; k++){
            long long temp_ans = solve(arr, i, k,dp) + solve(arr, k, j,dp) + (long long)arr[i]*arr[k]*arr[j];
            mn=min(mn, (int)temp_ans);
        }
        return dp[i][j]=mn;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(values, 0, n-1, dp);
    }
};
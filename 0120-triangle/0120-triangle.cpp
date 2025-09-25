class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n+1,1e8);
        for(int i=0;i<n;i++){
            dp[i]=0;
        }
        for(int i=n-1;i>=0;i--){
            int sz=triangle[i].size();
            vector<int> curr(n+1,1e8);
            for(int j=sz-1;j>=0;j--){
                int ans=triangle[i][j];
                ans+=min(dp[j],dp[j+1]);
                curr[j]=ans;
            }
            dp=curr;
        }
        return dp[0];
    }
};
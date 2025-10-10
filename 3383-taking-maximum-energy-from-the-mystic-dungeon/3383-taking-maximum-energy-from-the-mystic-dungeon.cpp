class Solution {
public:
    int dfs(int current , vector<int> &energy , int k, vector<int> &dp){
        if(current >= energy.size() ) return 0; 
        if(dp[current] != INT_MIN) return dp[current];
        int ans = energy[current];
        ans += dfs(current + k , energy , k , dp);
        return dp[current] = ans;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n , INT_MIN);
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            ans = max(ans, dfs(i , energy , k , dp));
        }
        return ans;
    }
};
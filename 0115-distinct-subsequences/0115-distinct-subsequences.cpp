/*class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
    if(m>n)return 0;
    if(m==n){
        if(s==t)return 1;
        else return 0;
    }
    for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            long long take=0;
            if(s[i-1]==t[j-1])take=dp[i-1][j-1];
            long long nottake=dp[i-1][j];
            dp[i][j] = (take + nottake) % MOD;
        }
    }
    return (int)dp[n][m];
    }
};*//*class Solution {
    vector<vector<int>> dp;
    int helper(string& s, string& t, int i, int j){
        if(i == s.size() and j == t.size()){
            return 1;
        }
        if(i >= s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        int not_take = helper(s, t, i+1, j);
        int take = 0;
        if(s[i] == t[j]){
            take = helper(s, t, i+1, j+1);
        }

        return dp[i][j] = take + not_take;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return helper(s, t, 0, 0);
    }
};*/

class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int m = t.size();

        if (m > n) return 0;

        vector<long long> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = curr[0] = 1;  // Base case: empty t can be matched by deleting all of s

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;  // Every row's dp[0] is 1
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] + prev[j]) % MOD;
                } else {
                    curr[j] = prev[j] % MOD;
                }
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool>prev(m+1,false);
        prev[0]=true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }
        for(int i=1;i<n+1;i++){
        vector<bool>curr(m+1,false);

            for(int j=1;j<m+1;j++){
                if (s[i-1] == p[j-1] || p[j-1] == '?') {  
                curr[j] = prev[j-1];
                }
                if (p[j-1] == '*') {
                curr[j] = prev[j] || curr[j-1];
            // '*' matches 1+ chars OR '*' matches 0 chars
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};
/*class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if (s[i-1] == p[j-1] || p[j-1] == '?') {  
                dp[i][j] = dp[i-1][j-1];
                }
                if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            // '*' matches 1+ chars OR '*' matches 0 chars
                }
            }
        }
        return dp[n][m];
    }
};*/
/*class Solution {
public:
    int dp[2001][2001];

    bool solve(int i, int j, string &s, string &p) {
        if (i >= s.length() && j >= p.length()) return true;  // Both exhausted
        if (j >= p.length()) return false;  // Pattern exhausted but string remains
        if (i >= s.length()) {  
            // Remaining pattern should only contain '*' for a match
            while (j < p.length()) {
                if (p[j] != '*') return false;
                j++;
            }
            return true;
        }
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {  
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        }

        if (p[j] == '*') {
            return dp[i][j] = solve(i + 1, j, s, p) || solve(i, j + 1, s, p);
            // '*' matches 1+ chars OR '*' matches 0 chars
        }

        return dp[i][j] = false;  
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};
*/
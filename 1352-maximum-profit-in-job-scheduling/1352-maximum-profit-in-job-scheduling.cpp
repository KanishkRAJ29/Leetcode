class Solution {
public:
    // (start, end, profit) tuples
    vector<tuple<int,int,int>> sep;

    // i = current job index
    // last = index of last-taken job (or -1 if none)
    // dp sized [n][n+1], memoizing on (i, last+1)
    int solve(int i, int last, vector<vector<int>>& dp) {
        int n = sep.size();
        if (i >= n) return 0;
        int lit = last + 1;                // shift so last==-1 → lit==0
        if (dp[i][lit] != -1) 
            return dp[i][lit];

        // Option 1: skip job i
        int ans = solve(i+1, last, dp);

        // Option 2: take job i, if it doesn't overlap
        int si = get<0>(sep[i]);
        int ei = get<1>(sep[i]);
        int pi = get<2>(sep[i]);
        if (last < 0 || si >= get<1>(sep[last])) {
            ans = max(ans, pi + solve(i+1, i, dp));
        }

        return dp[i][lit] = ans;
    }

    int jobScheduling(vector<int>& startTime, 
                      vector<int>& endTime, 
                      vector<int>& profit) {
        int n = startTime.size();
        sep.reserve(n);
        for (int i = 0; i < n; i++) {
            sep.emplace_back(startTime[i], 
                             endTime[i], 
                             profit[i]);
        }
        // sort by start time
        sort(sep.begin(), sep.end(),
             [&](auto &a, auto &b){
                 return get<0>(a) < get<0>(b);
             });

        // dp dimensions: n rows, (n+1) columns for last+1 = 0..n
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, dp);
    }
};

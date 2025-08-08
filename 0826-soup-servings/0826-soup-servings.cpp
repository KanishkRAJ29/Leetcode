class Solution {
public:
    double allCases(int A,int B,vector<vector<double>>&dp){
        
        if(A<=0&&B<=0)return 0.5;
        if(A<=0)return 1.0;
        if(B<=0)return 0;
        if(dp[A][B]!=-1)return dp[A][B];
        double one=0,two=0,three=0,four=0;
        one=allCases(A-4,B,dp);
        
            two=allCases(A-3,B-1,dp);
            three=allCases(A-2,B-2,dp);
            four=allCases(A-1,B-3,dp);
        
        return dp[A][B]=0.25*(one+two+three+four);
        
    }
    double soupServings(int n) {
        if(n>=5000)return 1;
       int m=ceil(n/25.0) ;
        vector<vector<double>>dp(m+1,vector<double>(m+1,-1.0));
        double all=allCases(m,m,dp);
        return all;
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2,int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=s1.length()||j>=s2.length()){
            return 0;
        }
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+solve(s1,s2,i+1,j+1);
        }
        return dp[i][j]=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,0));

        
       for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       }
       return dp[text1.size()][text2.size()];
    }
};/*class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2,int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=s1.length()||j>=s2.length()){
            return 0;
        }
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+solve(s1,s2,i+1,j+1);
        }
        return dp[i][j]=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
       return solve(text1,text2,0,0); 
    }
};*/
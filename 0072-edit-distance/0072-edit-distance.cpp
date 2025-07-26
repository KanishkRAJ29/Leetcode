class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=0;i<m+1;i++){
            prev[i]=i;
        }
        curr[0]=1;
        int i=1,j=1;
        
        for( i=1;i<n+1;i++){
            curr[0] = i;
            for( j=1;j<m+1;j++){
                if(w1[i-1]==w2[j-1])curr[j]=prev[j-1];
                else{
                    int in=curr[j-1];
                    int del=prev[j];
                    int rep=prev[j-1];
                    curr[j]=1+min({in,del,rep});
                }

            }
            prev=curr;
        }
        return prev[m];
        
    }
};/*class Solution {
public:
    int dp[501][501];
    int m,n;
    int solve(string s1, string s2,int i,int j){
        if(i==m){
            return n-j;
        }
        if(j==n){
            return m-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return solve(s1,s2,i+1,j+1);
        int insert=1+solve(s1,s2,i,j+1);
        int del=1+solve(s1,s2,i+1,j);
        int rep=1+solve(s1,s2,i+1,j+1);
        dp[i][j]=min({insert,del,rep});
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};*/
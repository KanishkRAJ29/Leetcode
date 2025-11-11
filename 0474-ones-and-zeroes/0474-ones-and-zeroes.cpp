class Solution {
public:

pair<int,int>count(string s)
{
    int one=0,zero=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        zero++;
        else
        one++;
    }
    return {zero,one};
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        
       
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));

       for(auto str:strs)
       {
            pair<int,int>p=count(str);
            int z=p.first;
            int o=p.second;

            for(int i=m;i>=z;i--)
            {
                for(int j=n;j>=o;j--)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i-z][j-o]);
                }
                
            }
       }
       return dp[m][n];
    }
};
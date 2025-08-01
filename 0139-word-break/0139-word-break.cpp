class Solution {
public:
    bool solve(unordered_set<string>&st,string s,int left,vector<int>&dp){
        if(left>=s.size()||st.find(s.substr(left,s.size()-left))!=st.end())return true;
        if(dp[left]!=-1)return dp[left]==1;
        bool ans=false;
        for(int k=left;k<s.size();k++){
            string leftstring=s.substr(left,k-left+1);
            if(st.find(leftstring)!=st.end()){
                bool curr=solve(st,s,k+1,dp);
                ans=ans||curr;

            }
        }
        if(ans)dp[left]=1;
        else dp[left]=0;
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        //vector<int>dp(s.size(),-1);
        //return solve(st,s,0,dp);
        
        vector<bool>dp(s.size()+1,false);
        dp[s.size()] = true;

        for(int left=s.size()-1;left>=0;left--){
            bool ans=false;
        for(int k=left;k<s.size();k++){
            string leftstring=s.substr(left,k-left+1);
            if(st.find(leftstring)!=st.end()){
                bool curr=dp[k+1];
                ans=ans||curr;

            }
        }
       
        dp[left]= ans;
        }
    return dp[0];

    }
};
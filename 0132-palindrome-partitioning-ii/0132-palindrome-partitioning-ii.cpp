class Solution {
public:
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
        /*int solve(int left, int right, string &s, vector<int>&dp) {
        if (left >= right || isPal(left, right, s)) return 0;
        if (dp[left] != -1) return dp[left];

        int minCuts = INT_MAX;
        for (int i = left; i < right; i++) {
            if (isPal(left, i, s)) {
                minCuts = min(minCuts, solve(i + 1, right, s, dp)+1);
            }
        }
        return dp[left] = minCuts;
    }*/
    int minCut(string s) {
        
        int n = s.length();
        vector<int>dp(n+1, 0);
        for(int left=n-1;left>=0;left--){
                int minCuts=INT_MAX;
                for(int i=left;i<n;i++){
                    if(isPal(left,i,s)){
                        minCuts=min(minCuts,dp[i+1]==INT_MAX?INT_MAX:dp[i+1]+1);
                    }
                
                dp[left]=minCuts;
            }
        }
        return dp[0]-1;

       // vector<int>dp(n, -1);
        //return solve(0, n - 1, s, dp);


    }
};/*
class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    
    int solve(string &s, int start, int end,vector<vector<int>> &dp) {
        
        if(dp[start][end] != -1) return dp[start][end];
        
        if(start >= end) return dp[start][end] = 0 ;
        
        if(isPalindrome(s,start,end) == true)
            return dp[start][end] = 0;
        
        int ans = INT_MAX;
        
        for(int ctr = start ; ctr < end ; ctr ++ ) {
            
            if(isPalindrome(s,start,ctr)==false)
                continue;
            
            int tempAns =  solve(s,ctr+1,end,dp) + 1;
            
            if(tempAns < ans) ans = tempAns;
        }
        
        return dp[start][end] = ans;
        
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
        return solve(s,0,s.length()-1,dp);
    }
};*/
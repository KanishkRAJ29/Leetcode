class Solution {
public:
    void solve(string s,set<string>&words,vector<string>&res,string &curr,int i){
        if(i==s.length()){
            res.push_back(curr);
            return;
        }
        for(int j=i+1;j<=s.size();j++){
            string w=s.substr(i,j-i);
            if(words.find(w)!=words.end()){
                string temp=curr;
                if(!curr.empty()){
                curr=curr+" "+w;
                }
                else curr=curr+w;
                solve(s,words,res,curr,j);
                curr=temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>words(wordDict.begin(),wordDict.end());
        vector<string>res;
        string curr="";
        solve(s,words,res,curr,0);
        return res;
    }
};
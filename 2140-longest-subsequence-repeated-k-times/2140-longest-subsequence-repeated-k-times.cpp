class Solution {
public:
    bool isKRepated(string &s,string &next,int k){
        int i=0;
        int matched=0;
        int n=s.size();
        int m=next.size();
        for(char ch:s){
            if(ch==next[i]){
                i++;
                if(i==m){
                    matched++;
                    i=0;
                    if(matched==k)return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        vector<int>candidates;
        for(int i=25;i>=0;i--){
            if(freq[i]>=k){
                candidates.push_back(i+'a');
            }
        }
        queue<string>q;
        for(int i=0;i<candidates.size();i++){
            q.push(string(1,candidates[i]));
        }
        string ans="";
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr.size()>ans.size())ans=curr;
            for(char ch:candidates){
                string next=curr+ch;
                if(isKRepated(s,next,k)){
                    q.push(next);
                }
            }
        }
    return ans;
    }
};
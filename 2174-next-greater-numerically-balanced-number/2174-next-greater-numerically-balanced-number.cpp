class Solution {
public:
    bool solve(int n){
        unordered_map<int,int>mp;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'0']++;
            if(mp[s[i]-'0']>s[i]-'0')return false;
        }
        for(auto [key,val]:mp){
            if(key!=val)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int i=n+1;
        while(true){
            if(solve(i))return i;
            i++;
        }
        return -1;
    }
};
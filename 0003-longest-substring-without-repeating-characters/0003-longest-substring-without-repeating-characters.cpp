class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            
            while(mp[s[j]]>1){
                if (--mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            if(mp.size()==j-i+1)ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
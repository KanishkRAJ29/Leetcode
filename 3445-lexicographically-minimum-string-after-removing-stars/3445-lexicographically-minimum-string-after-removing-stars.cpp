class Solution {
public:
    int findi(map<char,set<int>>& mp, int ind){
        for (auto& [ch, st] : mp) {
            auto it = st.lower_bound(ind);
            if (it == st.begin()) continue;
            --it;
            int val = *it;
            st.erase(it);
            return val;
        }
        return -1;
    }
    
    string clearStars(string s) {
       map<char,set<int>> mp;
       for (int i = 0; i < s.size(); i++) {
           if (s[i] == '#' || s[i] == '*') continue;
           mp[s[i]].insert(i);
       } 
       
       for (int i = 0; i < s.size(); i++) {
           if (s[i] == '*') {
               int ind = findi(mp, i);
               if (ind != -1)
                   s[ind] = '#';
           }
       }
       
       string ans = "";
       for (int i = 0; i < s.size(); i++) {
           if (s[i] == '#' || s[i] == '*') continue;
           ans += s[i];
       }
       
       return ans;
    }
};

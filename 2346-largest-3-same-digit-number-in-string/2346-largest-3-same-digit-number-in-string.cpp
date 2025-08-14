class Solution {
public:
    string largestGoodInteger(string num) {
      
        unordered_map<char,int>mp;
        int i=0,j=0;
        string ans="";
        while(j<num.size()){
            mp[num[j]]++;
           if(abs(i-j)==2&&mp.size()==1){
            string a=(num.substr(i,3));
            ans=max(ans,a);
           }
            while(j-i==2){
                mp[num[i]]--;
                if(mp[num[i]]==0){
                    mp.erase(num[i]);
                }
                i++;
            }
             j++;
        }
        return ans;
    }
};
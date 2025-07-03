class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        char ans='a';
        while(s.size()<k){
            string news="";
            for(int i=0;i<s.size();i++){
                if(s[i]!='z')news+=(s[i]+1);
                else news+='a';
            }
            if(s.size()+news.size()>=k){
                k-=s.size();
                 ans=news[k-1];
            }
            s+=news;
        }
        return ans;
    }
};
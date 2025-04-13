class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()==1)return s;
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        if(s.length()%2==0){
            for(int i=0;i<26;i++){
                if(freq[i]==0)continue;
                int num=freq[i]/2;
                char c='a'+i;
                string toCon(num,c);
                ans=ans+toCon;
            }

        string back=ans;
        reverse(back.begin(),back.end());
        ans=ans+back;
        return ans;
            
        }else{
            int odd=0;
            for(int i=0;i<26;i++){
                if(freq[i]==0)continue;
                if(freq[i]%2!=0){odd=i;
                                if(freq[i]==1)continue;}
                int num=freq[i]/2;
                char c='a'+i;
                string toCon(num,c);
                ans=ans+toCon;
            }
        string back=ans;
        reverse(back.begin(),back.end());
        string mid="a";
            mid[0]='a'+odd;
            ans+=mid;
        ans=ans+back;
        return ans;
        }
        
        return "";
    }
};
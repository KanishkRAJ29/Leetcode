class Solution {
public:
    string reverseWords(string s) {
        int j=s.size()-1;
        int i=j;
        string ans="";
        bool seenchar=false;
        int end=0;
        while(s[i]==' '){
            i--;
            j--;
        }
        while(s[end]==' '){
            end++;
        }
        while(i>=end){
            if(s[i]==' '){
                ans+=s.substr(i+1,j-i);
                ans+=' ';
                j=i-1;
                while(s[j]==' ')j--;
                i=j+1;
            }
            i--;
        }
        return ans+s.substr(end,j-end+1);
    }
};
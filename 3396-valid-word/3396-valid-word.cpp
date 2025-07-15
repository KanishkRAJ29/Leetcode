class Solution {
public:
    bool isAlpha(char c){
        if(c-'a'>=0&&c-'a'<=25)return true;
        else if(c-'A'>=0&&c-'A'<=25)return true;
        return false;
    }
    bool isVowel(char c){

        if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U')return false;;
        return true;
    }
    bool isValid(string s) {
        if(s.size()<3)return false;
        int i=0;
        int v=0,c=0;
        while(i<s.size()){
            if(isAlpha(s[i])&&isVowel(s[i]))v++;
            else if(isAlpha(s[i])&&!isVowel(s[i])){
                c++;
            }else if(!isAlpha(s[i])){
                if(s[i]-'0'<0||s[i]-'0'>9)return false;
            }
            i++;
        }
    if(c>=1&&v>=1)return true;
    return false;

    }
};
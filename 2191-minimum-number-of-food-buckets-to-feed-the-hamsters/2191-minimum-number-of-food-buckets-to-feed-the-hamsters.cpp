class Solution {
public:
    int minimumBuckets(string s) {
     int mini=0;
     int dot=0;
          if(s.size()>=2&&s[0]=='H'){
        if(s[1]=='.'){
        s[1]='B';
        mini++;}else if(s[1]=='H'){
            return -1;
        }
     } 
     for(int i=1;i<s.size()-1;i++){
        if(s[i]=='H'&&s[i-1]=='H'&&s[i+1]=='H')return -1;
        else if(s[i]=='H'){
            if(s[i-1]=='B')continue;
            if(s[i+1]=='H'&&s[i-1]=='.'){
                mini++;
                s[i-1]='B';
            }else{
                s[i+1]='B';
                mini++;
            }
        }
     }
if(s.size()>=2&&s[s.size()-1]=='H'){
        if(s[s.size()-2]=='.'){s[s.size()-2]='B';
        mini++;}
        else if(s[s.size()-2]=='H'){
            return -1;
        }
     }

     for(int i=0;i<s.size();i++){
        if(s[i]=='.')dot++;
     }
     if(dot==s.size())return 0;
     
     if(mini==0)return -1;
     else return mini;   
    }
};
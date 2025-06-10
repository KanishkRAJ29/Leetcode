class Solution {
public:
    string answerString(string s, int k) {
       if(k==1)return s;
       char largeChar='a';
       int ind=0;
       for(int i=0;i<s.size();i++){
        if(largeChar>=s[i])continue;
        largeChar=s[i];
        ind=i;
       }
       string result="";
       for (int i = 0; i < s.size(); i++) {
            if (s[i] == largeChar) {
                 int s_possible_beforeind=i+1;
                 string candidate="";
                if(s_possible_beforeind>=k){
                    candidate= s.substr(i,s.size()-i);
                }else{
                    int left=k-s_possible_beforeind;
                    candidate= s.substr(i,s.size()-left-i);
                }
                if (candidate > result) result = candidate;
            }
        }
      
    return result;
    }
};
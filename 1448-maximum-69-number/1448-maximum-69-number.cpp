class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        bool done=false;
        for(int i=0;i<s.size();i++){
            if(done)break;
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};
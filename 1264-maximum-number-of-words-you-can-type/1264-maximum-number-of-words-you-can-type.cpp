class Solution {
public:
    int canBeTypedWords(string t, string b) {
        vector<string>v;
        string s="";
        for(int i=0;i<t.size();i++){
            if(t[i]==' '){
                v.push_back(s);
                s="";
            }
            else{
                s.push_back(t[i]);
            }
        }
        if(s!="")v.push_back(s);
        int c=0;
        for(auto i:v){
            bool f=false;
            for(auto j:b){
                if(i.find(j)!=string::npos){
                    f=true;
                    break;
                }
            }
            if(!f)c++;
        }
        return c;
    }
};
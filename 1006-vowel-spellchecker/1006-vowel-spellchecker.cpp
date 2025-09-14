class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string convertToLower(string str){
        for(int i=0; i<str.length();i++){
            str[i]=tolower(str[i]);
        }
        return str;
    }
    string convert(string str){
        for(int i=0; i<str.length();i++){
            if(isVowel(str[i])){
                str[i]='*';
            }
        }
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>temp1;
        unordered_map<string,string>temp2;
        unordered_map<string,string>temp3;
        vector<string>ans;
        for(int i=0; i<wordlist.size();i++){
            string temp=wordlist[i];
            temp1.insert(temp);

            temp=convertToLower(temp);
            if(temp2.find(temp)==temp2.end()){
                temp2[temp]=wordlist[i];
            }

            temp=convert(temp);
            if(temp3.find(temp)==temp3.end()){
                temp3[temp]=wordlist[i];
            }
        }
        for(int i=0; i<queries.size();i++){
            string temp=queries[i];
            if(temp1.find(temp)!=temp1.end()){
                ans.push_back(temp);
                continue;
            }
            temp=convertToLower(temp);
            if(temp2.find(temp)!=temp2.end()){
                ans.push_back(temp2[temp]);
                continue;
            }
            temp=convert(temp);
            if(temp3.find(temp)!=temp3.end()){
                ans.push_back(temp3[temp]);
                continue;
            }
            ans.push_back("");
        }
        return ans;

    }
};
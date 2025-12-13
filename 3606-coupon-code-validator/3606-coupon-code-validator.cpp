class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>result;
        vector<tuple<int,string>>ans;
        for(int i=0;i<code.size();i++){
            if(!isActive[i])continue;
            if(code[i].size()==0)continue;
            int z=-1;;
            if(businessLine[i]=="electronics"){
                z=0;
            }else if(businessLine[i]=="grocery"){
                z=1;
            }else if(businessLine[i]=="pharmacy"){
                z=2;
            }else if(businessLine[i]=="restaurant"){
                z=3;
            }else continue;
            int isvalid=1;
            for(char c:code[i]){
                if(!(isalnum(c)||c=='_')){
                    isvalid=0;
                    break;
                }
            }
            if(isvalid){
                ans.emplace_back(z,code[i]);
            }
        }
        sort(ans.begin(),ans.end());
        for(auto& [x,c]:ans){
            result.push_back(c);
        }
        return result;
    }
};
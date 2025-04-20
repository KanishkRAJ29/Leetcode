class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int ans=0;
        for(const auto& pair : mp){
            int ind=pair.second;
            int val=pair.first;
            if(ind>val){
                 ans += ((ind + val) / (val + 1)) * (val + 1);
            }else ans+=val+1;
        }
        return ans;
    }
};
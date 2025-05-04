class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        int val=0;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0]<dominoes[i][1]){
                val=dominoes[i][0]*10+dominoes[i][1];
                mp[val]++;
            }else {
                 val=dominoes[i][1]*10+dominoes[i][0];
                 mp[val]++;
            }
        }
        
        int count=0;
        for(auto &[key,value]:mp){
            if(value>1)count+=value*(value-1)/2;
        }
        return count;
    }
};
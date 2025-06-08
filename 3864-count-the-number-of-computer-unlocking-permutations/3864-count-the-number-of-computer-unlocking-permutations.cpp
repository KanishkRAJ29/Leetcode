class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini=*min_element(complexity.begin(),complexity.end());
        if(complexity[0]!=mini)return 0;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]==mini){return 0;}
        }
        long long ans=1;
        int MOD=1e9+7;
        for(int i=1;i<complexity.size();i++){
            ans=(ans*i)%MOD;

        }
        return (int)ans;
    }
};
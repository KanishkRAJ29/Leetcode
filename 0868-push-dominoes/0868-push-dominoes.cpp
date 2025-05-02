class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans=dominoes;
        vector<int>dist(dominoes.size(),0);
        int latestr=-1;
        char last='.';
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='R'){
                latestr=i;
                last='R';
            }
            else if(dominoes[i]=='.'&&latestr!=-1&&last=='R'){
                dist[i]=abs(latestr-i);
                ans[i]='R';
            }
            else{
                last='L';
            }
        }
        last='.';
        int latestl=dominoes.size();
        int d=0;
        for(int i=dominoes.size()-1;i>=0;i--){
            if(dist[i]==-1)continue;
            if(dominoes[i]=='L'){
                latestl=i;
                last='L';
            }
            else if(dominoes[i]=='.'&&last=='L'){
                d=abs(latestl-i);
                if(dist[i]==0||d<dist[i]){
                    ans[i]='L';
                }
                else if(d==dist[i])ans[i]=dominoes[i];

            }else {
                last='R';
            }

        }

    return ans;
    }
};
class Solution {
public:
    int MOD=1e9+7;
        vector<string>first;
        vector<vector<int>>t;
    void fillcol(vector<string>&first,string curr,char last){
        if(curr.length()==3){
            first.push_back(curr);
            return;
        }
        for(char c:{'R','G','B'}){
            if(last==c)continue;
            fillcol(first,curr+c,c);
        }
        

    }
    int solve(int cur_i,int n){
        if(n==0)return 1;
        if(t[n][cur_i]!=-1){
            return t[n][cur_i];
        }
        string prev=first[cur_i];
        int total=0;
        for(int i=0;i<first.size();i++){
            string next = first[i];
            bool valid=true;
            for(int j=0;j<next.size();j++){
                if(next[j]==prev[j]){valid=false;break;}
            }
            if(valid){
                total=(total+solve(i,n-1))%MOD;
            }

        }
        return t[n][cur_i]=total;

    }
    int numOfWays(int n) {
        fillcol(first,"",'a');
        int ans=0;
        t.assign(n,vector<int>(first.size(),-1));
        for(int i=0;i<first.size();i++){
            ans=(ans+solve(i,n-1))%MOD;
        }
        return ans;
    }
};
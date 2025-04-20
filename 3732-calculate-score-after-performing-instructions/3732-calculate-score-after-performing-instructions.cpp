class Solution {
public:
    
    void solve(long long &score,vector<string>&in,vector<int>&val,int i){
        if(i<0||i>=in.size()){
            return;
        }
        if(in[i]=="0")return;
        else if(in[i]=="jump"){
            in[i]="0";
            return solve(score,in,val,i+val[i]);
        }
        else {
            score+=val[i];
            in[i]="0";
            return solve(score,in,val,i+1);
        }
    }
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score=0;
        solve(score,instructions,values,0);
        return score;
    }
};
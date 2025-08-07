class Solution {
public:
    int solve(string s){
        if(s.size()==1)return s[0]-'0';
        int sum=0;
        for(int i=s.size()-1;i>=0;i--){
            sum+=s[i]-'0';
        }
        return solve(to_string(sum));
    }
    int addDigits(int num) {
        string s=to_string(num);
        return solve(s);
    }
};
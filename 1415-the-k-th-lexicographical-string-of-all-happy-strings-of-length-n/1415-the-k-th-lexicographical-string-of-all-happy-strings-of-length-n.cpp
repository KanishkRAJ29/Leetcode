class Solution {
public:
    void backtrack(string &curr,string &res,int &k,vector<char>&lis,int n){
        if(curr.length()==n){
            if(--k==0)res=curr;
            return;
        }
        for(char ch:lis){
            if(curr.empty()||curr.back()!=ch){
                curr.push_back(ch);
                backtrack(curr,res,k,lis,n);
                if(!res.empty())return;
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>list={'a','b','c'};
        string curr="";
        string res="";
        backtrack(curr,res,k,list,n);
        return res;
    }
};
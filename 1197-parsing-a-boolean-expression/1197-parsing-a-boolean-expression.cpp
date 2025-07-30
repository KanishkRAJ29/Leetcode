class Solution {
public:
    bool solve(vector<char>&exp,char op){
        if(op=='!'){
            if(exp[0]=='t')return false;
            else return true;
        }else if(op=='|'){
            for(int i=0;i<exp.size();i++){
                if(exp[i]=='t')return true;
            }
            return false;
        }
        else{
for(int i=0;i<exp.size();i++){
                if(exp[i]=='f')return false;
            }
            return true;
        }
        return true;
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.size();i++){
            if(expression[i]==',')continue;
            if(expression[i]==')'){
                vector<char>exp;

                while(st.top()!='('){
                    exp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                bool val=solve(exp,op);
                if(val)st.push('t');
                else st.push('f');
            }else{
                st.push(expression[i]);
            }
        }
        if(st.top()=='t')return true;
        else return false;
    }
};/*
class Solution {
public:
    char solve(vector<char>exp,char op){
        if(op=='!'){
            return exp[0]=='t'?'f':'t';
        }
        if(op=='&'){
            for(int i=0;i<exp.size();i++){
                if(exp[i]=='f')return 'f';
            }

        }else if(op=='|'){
            for(int i=0;i<exp.size();i++){
                if(exp[i]=='t')return 't';
            }
            return 'f';
        }
        return 't';
    } 
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.length();i++){
            if(expression[i]==',')continue;
            if(expression[i]==')'){
                vector<char>exp;
                while(st.top()!='('){
                    exp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char val=solve(exp,op);
                st.push(val);
            }else{
                st.push(expression[i]);
            }
        }
        if(st.top()=='t')return true;
        else return false;

    }
};*/
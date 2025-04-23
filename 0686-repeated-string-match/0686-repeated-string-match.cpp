/*class Solution {
public:
    bool check(string b,string a){
        char fa=a[0];
        int len=a.length();
        string s="";
        for(int i=0;i<b.length();i++){
            if(b[i]==fa){
                s=b.substr(i,len);
                if(s==a)return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        bool c=check(b,a);
        string s="";
        int n=(b.length()/a.length())+a.length();
        for(int i=1;i<n;i++){
            s+=a;
            if(check(s,b))return i;
        }
        return -1;
    }
};*/class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Keep appending 'a' until the length of repeated string >= length of b
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring now or after one more repeat
        if (repeated.find(b) != string::npos) return count;
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        return -1;
    }
};

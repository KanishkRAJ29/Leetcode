class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=n%2;
        n=n/2;

        while(n){
            int b=n%2;
            if(a==b){
                return false;
            }
            a=b;
            n=n/2;
        }
        return true;
    }
};
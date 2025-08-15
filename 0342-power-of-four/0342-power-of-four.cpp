class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1){
            return false;
        }
        int x=round(log(n)/log(4));
        if(pow(4,x)==n)return true;
        return false;
    }
};
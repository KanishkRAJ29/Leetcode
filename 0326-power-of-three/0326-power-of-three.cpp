class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1){
            return false;
        }
        int x=round(log(n)/log(3));
        if(pow(3,x)==n)return true;
        return false;
    }
};
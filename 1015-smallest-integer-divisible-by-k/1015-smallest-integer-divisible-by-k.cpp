class Solution {
public:
    int smallestRepunitDivByK(int k) {

        if(k == 1) {
            return 1 ;
        }

        if(k % 2 == 0 || k % 5 == 0) {
            return -1 ;
        }

        int len = 0, mod = 0 ;

        while(len <= k) {
            mod = (mod * 10 + 1) % k ;
            ++len ;
            if(mod == 0) {
                return len ;
            }
        }

        return -1 ;

    }
};
class Solution {
public:
    bool makeStringsEqual(string s, string target) {

        int tnt1 = 0;
        int tnt0 = 0;
       
        for (auto it : target) {
            if (it == '0') {
                tnt0++;
            } else {
                tnt1++;
            }
        }

        int cnt1 = 0;
        int cnt0 = 0;
        for (auto it : s) {
            if (it == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
 if((cnt1==tnt1)&&(cnt0==tnt0)){
            return true;
        }
        if (cnt0 == s.size() || tnt0 == target.size()) {
            return false;
        }

        return true;
    }
};
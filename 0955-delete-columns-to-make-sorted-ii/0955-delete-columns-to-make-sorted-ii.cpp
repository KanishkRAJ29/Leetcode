class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), ans = 0;
        vector<string> strSoFar(m, "");
        for(int col = 0; col < n; col++) {
            bool valid = true;
            for(int row = 1; row < m; row++) {
                if(strSoFar[row - 1] < strSoFar[row]) {
                    continue;
                }
                if(strs[row - 1][col] > strs[row][col]) {
                    valid = false;
                    break;
                }
            }
            if(valid == false) {
                ans++;
            } else {
                for(int row = 0; row < m; row++) {
                    strSoFar[row] += strs[row][col]; 
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        long long lCount = 0, cCount = 0, tCount = 0;
        long long original_ans = 0, ans = 0;
        long long tillC = 0;
        for(char c : s) {
            if(c == 'L') lCount++;
            else if(c == 'C') {
                cCount++;
                tillC += lCount;
            }
            else if(c == 'T') {
                tCount++;
                original_ans += tillC;
            }
        }
        
        vector<long long> lcPrefix(n, 0), ctSuffix(n, 0);
        // lc prefix
        long long lCount2 = 0, lcCount = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') lCount2++;
            else if(s[i] == 'C') {
                lcCount += lCount2;
            }
            lcPrefix[i] = lcCount;
        }

        // ct suffix
        long long tCount2 = 0, ctCount = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == 'T') tCount2++;
            else if(s[i] == 'C') {
                ctCount += tCount2;
            }
            ctSuffix[i] = ctCount;
        }


        long long inc = 0;
        // for L & T
        lCount = 0, cCount = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') lCount++;
            else if(s[i] == 'C') cCount++;
            else if(s[i] == 'T') tCount--;
            // placing C here
            inc = max(inc, lCount * tCount);
            // placing L here (before)
            inc = max(inc, ctSuffix[i]);
            // placing T here (after)
            inc = max(inc, lcPrefix[i]);
        }

        return original_ans + inc;
    }
};
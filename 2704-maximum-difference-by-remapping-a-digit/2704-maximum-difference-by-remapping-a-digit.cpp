class Solution {
public:
    int minMaxDifference(int num) {
        int max = num;
        int dig = log10(num) + 1;
        
        vector<int> digitArr(dig, 0);
        
        // Fill digits in reverse
        digitArr[0] = max % 10;
        for(int i = 1; i < dig; i++) {
            max = max / 10;
            digitArr[i] = max % 10;
        }
        
        // Reverse to get the actual digit order
        reverse(digitArr.begin(), digitArr.end());

        // Find first digit not 9 to replace for max
        int i = 0;
        while (i < digitArr.size() && digitArr[i] == 9) {
            i++;
        }

        int maxi = (i < digitArr.size()) ? digitArr[i] : 9;  // default to 9 if all 9s
        int mini = digitArr[0];

        // Create max number by replacing all maxi digits with 9
        vector<int> n = digitArr;
        for (int j = 0; j < n.size(); j++) {
            if (n[j] == maxi) n[j] = 9;
        }

        // Create min number by replacing all mini digits with 0
        vector<int> m = digitArr;
        for (int j = 0; j < m.size(); j++) {
            if (m[j] == mini) m[j] = 0;
        }

        // Convert vectors to integer
        int one = 0, two = 0;
        for (int j = 0; j < n.size(); j++) {
            one += n[j] * pow(10, n.size() - j - 1);
        }
        for (int j = 0; j < m.size(); j++) {
            two += m[j] * pow(10, m.size() - j - 1);
        }

        return one - two;
    }
};

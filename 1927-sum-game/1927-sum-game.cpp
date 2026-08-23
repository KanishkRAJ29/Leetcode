class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQuestion = 0;
        int rightQuestion = 0;

        // Process left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftQuestion++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        // Process right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightQuestion++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of ? -> Alice wins
        if ((leftQuestion + rightQuestion) % 2 == 1) {
            return true;
        }

        // Even number of ?
        return leftSum - rightSum !=
               (rightQuestion - leftQuestion) * 9 / 2;
    }
};
class Solution {
public:
    int divisors(int x) {
        int sum = 0;
        int count = 0;

        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                int d1 = i;
                int d2 = x / i;

                if (d1 == d2) {
                    count++;
                    sum += d1;
                } else {
                    count += 2;
                    sum += d1 + d2;
                }

                if (count > 4)
                    return 0;
            }
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += divisors(x);
        }
        return totalSum;
    }
};
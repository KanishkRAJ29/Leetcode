class Solution {
public:
    const int e = 1000000007;

    // Function to perform modular exponentiation
    long long modExpo(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long num_of_five = (n + 1) / 2;
        long long num_of_four = n / 2;

        // Calculate (5^num_of_five) % e
        long long pow5 = modExpo(5, num_of_five, e);

        // Calculate (4^num_of_four) % e
        long long pow4 = modExpo(4, num_of_four, e);

        // Result is (pow5 * pow4) % e
        return (pow5 * pow4) % e;
    }
};
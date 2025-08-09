#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;  // Negative numbers and 0 are not powers of two
        }
        
        // Use log2(n) to check if the logarithm is an integer
        int log2n = log2(n);
        return pow(2, log2n) == n;
    }
};
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1; // since we start with 1

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;     // move to next sibling
                k -= steps; // skip this subtree
            } else {
                curr *= 10; // go deeper into subtree
                k -= 1;
            }
        }
        return curr;
    }

    long countSteps(int n, long first, long last) {
        long steps = 0;
        while (first <= n) {
            steps += min(n + 1L, last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }
};

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, odd_even = 0, even_odd = 0;
        for (int num : nums) {
            if (num % 2) {
                odd++;
                odd_even = even_odd + 1;
            } else {
                even++;
                even_odd = odd_even + 1;
            }
        }
        return max({odd, even, odd_even, even_odd});
    }
};
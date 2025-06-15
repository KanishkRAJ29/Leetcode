class Solution {
public:
    int maxDiff(int num) {
        int second = num;
        int numdig = log10(num) + 1;

        vector<int> nums(numdig, 0);
        for (int i = 0; i < numdig; i++) {
            nums[i] = second % 10;
            second /= 10;
        }

        vector<int> v = nums;

        // Create min number (replace a digit with 1 or 0)
        int toReplaceMin = -1;
        int replaceWithMin = -1;
        if (nums[numdig - 1] != 1) {
            toReplaceMin = nums[numdig - 1];  // first digit (most significant)
            replaceWithMin = 1;
        } else {
            for (int i = numdig - 2; i >= 0; i--) {
                if (nums[i] != 0 && nums[i] != 1) {
                    toReplaceMin = nums[i];
                    replaceWithMin = 0;
                    break;
                }
            }
        }

        for (int i = 0; i < numdig; i++) {
            if (nums[i] == toReplaceMin) {
                nums[i] = replaceWithMin;
            }
        }

        int two = 0;
        for (int i = numdig - 1; i >= 0; i--) {
            two = two * 10 + nums[i];
        }

        // Create max number (replace a digit with 9)
        int toReplaceMax = -1;
        for (int i = numdig - 1; i >= 0; i--) {
            if (v[i] != 9) {
                toReplaceMax = v[i];
                break;
            }
        }

        for (int i = 0; i < numdig; i++) {
            if (v[i] == toReplaceMax) {
                v[i] = 9;
            }
        }

        int one = 0;
        for (int i = numdig - 1; i >= 0; i--) {
            one = one * 10 + v[i];
        }

        return one - two;
    }
};

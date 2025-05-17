class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c = 0, i = 0, j = nums.size() - 1;
        // ——— Pass 1: move 0’s to front ———
        while (i < j) {
            if (nums[i] == c) {
                i++; 
                continue;
            } else if (nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
                continue;
            }
            while (j > 0 && nums[j] != c) j--;
            if (i < j && nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
            }
        }
        while (i < nums.size() && nums[i] == 0) {
    i++;
}

        // ——— Pass 2: move 1’s just after the 0’s ———
        c = 1;
        j = nums.size() - 1;
        // **keep i where it left off** (i now == first non‑0 index)
        while (i < j) {
            if (nums[i] == c) {
                i++; 
                continue;
            } else if (nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
                continue;
            }
            while (j > 0 && nums[j] != c) j--;
            if (i < j && nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
            }
        }

        // ——— Skip past all the 1’s so we don’t accidentally swap one in pass 3 ———
        // (this is the one‐line “fix”)
        while (i < (int)nums.size() && nums[i] == 1) {
            i++;
        }

        // ——— Pass 3: move 2’s to the end ———
        c = 2;
        j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == c) {
                i++; 
                continue;
            } else if (nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
                continue;
            }
            while (j > 0 && nums[j] != c) j--;
            if (i < j && nums[j] == c) {
                swap(nums[j], nums[i]);
                i++; 
                j--;
            }
        }
    }
};

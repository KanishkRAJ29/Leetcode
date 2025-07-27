class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if(nums.size()<=2)return 0;
        int lb=0;
        int rb=2;
        int ans=0;
        int n=nums.size();
        for (int i = 1; i < n-1; i++) {
    // 1) skip left‑duplicates only adjusting i
    while (i < n-1 && nums[i] == nums[i-1]) {
        i++;
    }
    if (i >= n-1) break;

    // 2) reset rb for this i
    int rb = i + 1;
    // skip right‑duplicates
    while (rb < n && nums[rb] == nums[i]) {
        rb++;
    }
    if (rb >= n) break;

    // 3) compare for hill/valley
    if ((nums[lb] > nums[i] && nums[rb] > nums[i]) ||
        (nums[lb] < nums[i] && nums[rb] < nums[i])) {
        ans++;
        lb = i;
    }
}

        return ans;
    }
};
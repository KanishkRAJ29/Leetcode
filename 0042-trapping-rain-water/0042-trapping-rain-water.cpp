class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftlow = 0;

        while (leftlow < height.size() - 1) {
            if (height[leftlow] == 0) {
                leftlow++;
                continue;
            }

            // Step 1: Find right boundary
            int righthigh = leftlow + 1;
            int maxRight = righthigh;
            for (int i = righthigh; i < height.size(); i++) {
                if (height[i] >= height[leftlow]) {
                    righthigh = i;
                    break;
                }
                if (height[i] > height[maxRight]) {
                    maxRight = i;
                }
            }

            // If we found taller or equal right wall
            if (height[righthigh] >= height[leftlow]) {
                int boundedHeight = height[leftlow];
                for (int i = leftlow + 1; i < righthigh; i++) {
                    ans += (boundedHeight - height[i]);
                }
                leftlow = righthigh;
            }
            // Else: use maxRight as the best available
            else {
                int boundedHeight = height[maxRight];
                for (int i = leftlow + 1; i < maxRight; i++) {
                    ans += (boundedHeight - height[i]);
                }
                leftlow = maxRight;
            }
        }

        return ans;
    }
};

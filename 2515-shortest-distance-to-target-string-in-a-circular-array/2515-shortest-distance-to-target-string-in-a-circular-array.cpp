class Solution {
public:
    int closestTarget(vector<string>& words, string target, int s) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(s - i);
                ans = min(ans, min(diff, n - diff));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
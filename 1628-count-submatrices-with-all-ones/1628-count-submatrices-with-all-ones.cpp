class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        for (int sr = 0; sr < n; sr++) {
            vector<int> merged(m, 1);

            for (int er = sr; er < n; er++) {
                // Merge current row with previous
                for (int j = 0; j < m; j++) {
                    merged[j] = merged[j] & mat[er][j];
                }

                // Count consecutive 1s in merged
                int consecutive = 0;
                for (int j = 0; j < m; j++) {
                    if (merged[j] == 1) {
                        consecutive++;
                        count += consecutive;
                    } else {
                        consecutive = 0;
                    }
                }
            }
        }
        return count;
    }
};

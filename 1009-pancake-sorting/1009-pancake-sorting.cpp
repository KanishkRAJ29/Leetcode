class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        int n = arr.size(); 

        for (int target = n; target > 0; target--) {
            int i = find(arr.begin(), arr.end(), target) - arr.begin();

            if (i == target - 1) {
                continue; // already slotted correctly
            }

            // Flip to move elem to the front
            if (i != 0) {
                reverse(arr.begin(), arr.begin() + i + 1);
                ret.push_back(i+1); // 1 indexed
            }

            reverse(arr.begin(), arr.begin() + target);
            ret.push_back(target);
        }

        return ret;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> nge(nums2.size(), -1);
        stack<int> st;

        // Compute Next Greater Element for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums2[i]);
            mp[nums2[i]] = i; // map value to index in nums2
        }

        // Use map to get NGE for nums1 elements
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int ind = mp[nums1[i]];
            ans.push_back(nge[ind]);  // ✅ fixed from nge[i] to nge[ind]
        }

        return ans;
    }
};

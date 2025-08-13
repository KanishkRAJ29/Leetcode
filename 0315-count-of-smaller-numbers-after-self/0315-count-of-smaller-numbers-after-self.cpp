class Solution {
public:
    vector<int> st;

    // point update: add 1 at position 'pos'
    void update(int node, int l, int r, int pos) {
        if (l == r) {
            st[node] += 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(2*node + 1, l, mid, pos);
        else update(2*node + 2, mid + 1, r, pos);
        st[node] = st[2*node + 1] + st[2*node + 2];
    }

    // range query: sum on [ql..qr]
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[node];
        int mid = l + (r - l) / 2;
        return query(2*node + 1, l, mid, ql, qr) + query(2*node + 2, mid + 1, r, ql, qr);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return {};

        // offset only if there are negative elements
        int minv = *min_element(nums.begin(), nums.end());
        int offset = (minv < 0) ? -minv : 0;

        // apply offset and find max value
        int maxv = INT_MIN;
        for (int i = 0; i < N; ++i) {
            nums[i] += offset;
            maxv = max(maxv, nums[i]);
        }

        // if all numbers became 0 (e.g., input was all -k), maxv could be 0
        // build segment tree for range [0..maxv]
        st.assign(4 * (maxv + 1), 0);

        vector<int> ans(N, 0);

        // iterate from right to left
        for (int i = N - 1; i >= 0; --i) {
            int val = nums[i];
            if (val - 1 >= 0) {
                ans[i] = query(0, 0, maxv, 0, val - 1);
            } else {
                ans[i] = 0;
            }
            update(0, 0, maxv, val);
        }
        return ans;
    }
};

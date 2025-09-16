typedef long long ll;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<ll> st;
        st.push(nums[0]);
        for(int i = 1; i < n; ++i) {
            int curr = nums[i];
            while(!st.empty()) {
                ll top = st.top();
                ll gcd = __gcd(top, 1LL * curr);
                if(gcd == 1) break;
                ll lcm = 1LL * top * curr / gcd;
                st.pop();
                curr = lcm;
            }
            st.push(curr);
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
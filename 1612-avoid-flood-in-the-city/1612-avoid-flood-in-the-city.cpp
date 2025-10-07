class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = (int)rains.size();
        vector<int> ans(n, 1);                // default 1 for unused dry days
        unordered_map<int,int> last;          // lake -> last filled index
        set<int> dryIdx;                      // indices of zero-days

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryIdx.insert(i);             // we can choose later which lake to dry
            } else {
                int lake = rains[i];
                ans[i] = -1;                  // raining today
                if (last.count(lake)) {
                    // need a dry day after last[lake]
                    auto it = dryIdx.upper_bound(last[lake]);
                    if (it == dryIdx.end()) return {}; // no valid dry day -> impossible
                    ans[*it] = lake;          // dry this lake on that zero-day
                    dryIdx.erase(it);
                }
                last[lake] = i;
            }
        }
        // remaining zero-days already set to 1
        return ans;
    }
};

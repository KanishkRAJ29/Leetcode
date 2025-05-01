#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks,
                      vector<int>& workers,
                      int pills,
                      int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(),  tasks.end());
        sort(workers.begin(), workers.end());

        int lo = 1, hi = min(n, m), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    // Try to assign the 'mid' easiest tasks using up to 'pills' boosts.
    bool canAssign(int mid,
                   const vector<int>& tasks,
                   const vector<int>& workers,
                   int pills,
                   int strength) {
        multiset<int> ws;
        // Take the mid strongest workers into the multiset
        int m = workers.size();
        for (int i = m - mid; i < m; ++i) {
            ws.insert(workers[i]);
        }

        int remP = pills;
        // Assign tasks[mid-1] down to tasks[0]
        for (int i = mid - 1; i >= 0; --i) {
            int t = tasks[i];
            auto it = prev(ws.end());
            if (*it >= t) {
                // direct assignment
                ws.erase(it);
            }
            else {
                // try pill
                if (remP == 0) return false;
                auto jt = ws.lower_bound(t - strength);
                if (jt == ws.end()) return false;
                ws.erase(jt);
                --remP;
            }
        }
        return true;
    }
};

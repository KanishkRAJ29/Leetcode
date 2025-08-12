class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int findParent(int x) {
        if (p[x] != x) p[x] = findParent(p[x]);
        return p[x];
    }

    void Union(int a, int b) {
        int x = findParent(a);
        int y = findParent(b);
        if (x == y) return;
        if (r[x] > r[y]) p[y] = x;
        else if (r[x] < r[y]) p[x] = y;
        else { p[y] = x; r[x]++; }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& account) {
        int n = account.size();
        if (n == 0) return {};

        unordered_map<string,int> mp;   // email -> index
        DSU d(n);

        // union accounts that share an email
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < account[i].size(); ++j) {
                string &email = account[i][j];
                if (mp.count(email)) {
                    d.Union(mp[email], i);
                } else {
                    mp[email] = i;
                }
            }
        }

        // ans indexed by root index: collect emails in sets (keeps sorted order)
        vector< set<string> > ans(n);
        vector<string> names(n, "");

        for (int i = 0; i < n; ++i) {
            int root = d.findParent(i);
            // set the name for this root (name is same for all merged accounts)
            names[root] = account[i][0];
            for (int j = 1; j < account[i].size(); ++j) {
                ans[root].insert(account[i][j]);
            }
        }

        // build result
        vector<vector<string>> res;
        for (int i = 0; i < n; ++i) {
            if (!ans[i].empty()) {
                vector<string> tmp;
                tmp.push_back(names[i]);
                for (const auto &em : ans[i]) tmp.push_back(em);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

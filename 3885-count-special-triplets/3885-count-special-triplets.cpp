class Solution {
public:
    int MOD = 1e9 + 7;

    long long modInverse(long long a, int mod) {
        long long res = 1;
        long long power = mod - 2;

        while (power > 0) {
            if (power % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            power /= 2;
        }

        return res;
    }

    int findCount(const vector<int>& indices, int midind) {
        int small = upper_bound(indices.begin(), indices.end(), midind) - indices.begin();
        int large = indices.size() - small;
        return (1LL * small * large) % MOD;
    }

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [_, vec] : mp) {
            sort(vec.begin(), vec.end()); // Required for binary search
        }

        long long ans = 0;

        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int x : nums) {
            if (x % 2 == 1) continue;
            int mid = x / 2;
            if (!mp.count(mid)) continue;

            const auto& midIndices = mp[mid];
            const auto& xIndices = mp[x];

            if (x == mid) {
                int n = midIndices.size();
                if (n >= 3) {
                    long long inv6 = modInverse(6, MOD);
                    ans = (ans + ((1LL * n * (n - 1) % MOD * (n - 2) % MOD) * inv6 % MOD)) % MOD;
                }
                continue;
            }

            for (int s : midIndices) {
                ans = (ans + findCount(xIndices, s)) % MOD;
            }
        }

        return (int)ans;
    }
};

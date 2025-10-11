class Solution {
public:

    long long maximumTotalDamage(vector<int>& power) {
        vector<int> compress = power; long long n = power.size();
        compress.push_back(0);
        sort(compress.begin(),compress.end());
        auto it = unique(compress.begin(),compress.end());
        compress.erase(it , compress.end());
        vector<long long> dp(compress.size() , 0);
        long long ans = -1;
        unordered_map<long long,long long> freq;
        for(long long i : power) freq[i] ++;
        for(long long i = 1 ; i < compress.size() ; i ++){
            long long powerofthis = compress[i];
            long long hh = lower_bound(compress.begin(),compress.end(),powerofthis - 2) - compress.begin(); 
            long long h = lower_bound(compress.begin(), compress.end(), powerofthis) - compress.begin();
            if(hh > 0) hh --;
            else hh = h;
            dp[h] = max(dp[h] + freq[powerofthis]*powerofthis , dp[hh] + freq[powerofthis]*powerofthis);
            ans = max(ans, dp[h]);
            dp[h] = max(dp[h],dp[h - 1]);
        }
        return ans;
    }
};
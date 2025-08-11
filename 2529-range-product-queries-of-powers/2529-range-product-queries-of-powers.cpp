class Solution {
public:
 int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        int i=30;
        while(n!=0){
            if((1<<i)>n){
                i--;
                continue;
            }
            else {
                n-=(1<<i);
                powers.push_back((1<<i));
                
            }
        }
        sort(powers.begin(),powers.end());
       vector<int> prefix(powers.size());
       prefix[0]=powers[0];
        
        vector<int>ans;
        for (int i = 0; i < queries.size(); i++) {
    int p = 1;
    for (int j = queries[i][0]; j <= queries[i][1]; j++) {
        p = ((long long)p * powers[j]) % mod;
    }
    ans.push_back(p);
}
        return ans;
    }
};
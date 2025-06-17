class Solution {
public:
int mx=1e5;
int MOD=1e9+7;
vector<long long>fact;
vector<long long>inv_fact;
    long long qpow(long long x,int n){
        long long res=1;
        while(n){
            if(n&1){
                res=res*x%MOD;
            }
            x=x*x%MOD;
            n>>=1;
        }
        return res;
    }
    int comb(int n,int k){
        return (fact[n]*inv_fact[n-k])%MOD *inv_fact[k]%MOD;
    }
    void init(int n){
        fact.resize(n);
    inv_fact.resize(n);
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*i%MOD;
        }
        inv_fact[n-1]=qpow(fact[n-1],MOD-2);
        for(int i=n-1;i;i--){
            inv_fact[i-1]=inv_fact[i]*i%MOD;
        }

    }
    int countGoodArrays(int n, int m, int k) {
        init(n);
         return 1LL * comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;

    }
};
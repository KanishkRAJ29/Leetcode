class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        if(m>n)return flowerGame(m,n);
        int odd=(n+1)/2;
        int even=n/2;
        for(int i=1;i<=m;i++){
            if(i%2==1){
                ans+=even;
            }else ans+=odd;
        }
        return ans;
    }
};
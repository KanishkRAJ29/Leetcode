class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0 || n==2)return 1;
        if(n==1)return 0;
        int next=0;
        for(int i=1;i<=2*n;i=i*2){
            if(i>n){next=i;
            break;}
        }
        return next-n-1;
    }
};
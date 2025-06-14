class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans=0;
        if(m>n){
           for(int i=1;i<=n;i++){
            ans+=i;;
        } 
        }else{

        
        
        for(int i=1;i<m;i++){
            ans+=i;;
        }
        for(int i=m;i<=n;i++){
            if(i%m!=0)ans+=i;
            else ans-=i;
        }}
        return ans;
    }
};
class Solution {
public:
    int smallestNumber(int n) {
        int x;
        for(int i=0;i<64;i++){
            x=pow(2,i);
            if(x>n){
                return x-1; 
            }
        }
        return 0;
    }
};
class Solution {
public:
    int getNthDigitFromLeft(int num, int n) {
    int totalDigits = log10(num) + 1;
    if(n > totalDigits)
        return -1;  // Invalid
    int divisor = pow(10, totalDigits - n);
    return (num / divisor) % 10;
}
    int countSymmetricIntegers(int low, int high) {
        int ans=0;

        for(int i=low;i<=high;i++){
            int count=0;
            int dig=log10(i)+1;
            if(dig%2!=0)continue;
            else{
                for(int j=0;j<dig;j++){
                    if(j<dig/2){

                        count+=getNthDigitFromLeft(i, j+1);
                    }
                    else{
                        count-=getNthDigitFromLeft(i, j+1);
                    }
                }
                if(count==0)ans++;
            }
        }
        return ans;
    }
};
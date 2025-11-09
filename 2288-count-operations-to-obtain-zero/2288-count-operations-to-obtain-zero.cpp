/*class Solution {
public:
    int ans=0;
    void count(int a,int b){
        if(a==0||b==0)return;
        if(a>b){
            a-=b;
            ans++;
            count(a,b);
        }
        else if(b>a){
            b-=a;
            ans++;
            count(b,a);
        }else if(a==b){
            ans++;
            return;
        }
    }
    int countOperations(int num1, int num2) {
        count(num1,num2);
        return ans;
    }
};*/
class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;  // total number of subtraction operations
        while (num1 && num2) {
            // each step of the Euclidean algorithm
            res += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};
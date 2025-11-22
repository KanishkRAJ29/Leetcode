class Solution {
public:
   /* int digSum(int n){
        if(n<10)return n;
        int dig=log10(n)+1;
        string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]-'0');
        }
        return digSum(sum);
    }*/

    int add(int n){
        int ans=0;
        n++;
        if(n%3==0)return 1;
        
        return 2;
    }
    int sub(int n){
        int ans=0;
        n--;
        if(n%3==0)return 1;
        else return 2;
    }

    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0)continue;
            int minAdd=add(nums[i]);
            int minSub=sub(nums[i]);
            ans+=min(minAdd,minSub);

        }
        return ans;
    }
};
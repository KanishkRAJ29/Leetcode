class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int allzero=1;
        int total=0;
        for(int x:nums){
            total^=x;
            if(x>0){
                allzero=0;
            }
        }
        if(total>0)return n;
        if(allzero==1){
            return 0;
        }else return n-1;
    }
};
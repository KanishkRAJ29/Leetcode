class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,currentlen=0,maxval=0;
        for(int num:nums){
            if(num>maxval){
                maxval=num;
                ans=currentlen=0;
            }
            if(num==maxval){
                currentlen++;
            }else{
                currentlen=0;
            }
            ans=max(ans,currentlen);
        }
        return ans;
    }
};
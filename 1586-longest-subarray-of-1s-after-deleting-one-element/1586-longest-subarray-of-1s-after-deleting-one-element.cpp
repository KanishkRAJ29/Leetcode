class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        int curr=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                curr=0;
            }else{
                curr+=1;
                ans=max(ans,curr);
                left[i]=curr;
            }
        }
        curr=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                curr=0;
            }else{
                curr+=1;
                ans=max(ans,curr);

                right[i]=curr;
            }
        }
        bool flag=true;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==0){
                flag=false;
                ans=max(ans,left[i-1]+right[i+1]);
            }
        }
        if(nums[0]==0||nums[nums.size()-1]==0)flag=false;
        if(flag)return ans-1;
        else return ans;
    }
};
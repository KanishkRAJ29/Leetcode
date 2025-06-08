class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int count=0;
        vector<int>two=nums;
        bool flag=false;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==-1){
                
                if(i==nums.size()-1){
                    flag=false;
                    break;
                };
                count++;
                if(count>k){
                    flag=false;
                    break;
                };
                nums[i]=1;
                nums[i+1]*=-1;
            }
        }
        int val=accumulate(nums.begin(),nums.end(),0);
        if(val==nums.size())return true;
        bool f=false;
        count=0;
        for(int i=0;i<two.size();i++){
            if(two[i]==1){
                
                if(i==two.size()-1){
                    f=false;
                    break;
                };
                count++;
                if(count>k){
                    f=false;
                    break;
                };
                two[i]=-1;
                two[i+1]*=-1;
            }
        }
        val=accumulate(two.begin(),two.end(),0);
        if(abs(val)==nums.size())return true;
        if(f||flag)return true;
        return false;


    }
};
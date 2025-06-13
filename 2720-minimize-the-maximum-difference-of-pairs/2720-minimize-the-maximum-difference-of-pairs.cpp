class Solution {
public:

    int countFind(vector<int>&nums,int thresh){
        int index=0;
        int count=0;
        while(index<nums.size()-1){
            if(nums[index+1]-nums[index]<=thresh){
                count++;
                index++;
            }
            index++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
       
        if(nums.size()<2||p==0)return 0;
        
        int left=0;
        int right=nums[nums.size()-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            if(countFind(nums,mid)>=p){
                right=mid;
            }else{
                left=mid+1;
            }
        }

        return left;
    }
};
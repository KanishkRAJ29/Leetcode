class Solution {
public:
    void calculatenew(int i,vector<int>& a,vector<int>& nums){
        if(i!=0&&i!=nums.size()){
            a[i-1]=nums[i-1]+nums[i];
            a[i]=nums[i]+nums[i+1];
        }
        else if(i==0){
            a[i]=nums[i]+nums[i+1];
        }else{
            a[i-1]=nums[i-1]+nums[i];
        }
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums)return 0;
        vector<int>adjSum(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++){
            adjSum[i]=nums[i]+nums[i+1];
        }
        int count=0;
        bool flag=true;
        while(flag){
          vector<int>temp=nums; 
            sort(temp.begin(),temp.end());
            if(temp==nums){flag=false;
                           break;}
            auto it = min_element(adjSum.begin(), adjSum.end());

            int i = distance(adjSum.begin(), it);
            nums[i+1]=adjSum[i];
            nums.erase(nums.begin() + i);
            adjSum.erase(adjSum.begin()+i);
            calculatenew(i,adjSum,nums);
            count++;
        }
        return count;
        
    }
};
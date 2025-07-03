class Solution {
public:
    int search(vector<int>& nums, int target) {
        int maxatright = nums[nums.size() - 1];
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int minatleft = nums[0];
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
           
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

            if(minatleft<=nums[mid]){
                if(target>=minatleft&&target<nums[mid]){
                    
                    high=mid-1;
                  if(high>=0)   maxatright=nums[high];
                }else {low=mid+1;
                   if(low<nums.size()) minatleft=nums[low];
                }
            }
            else{
                if(target<=maxatright&&target>nums[mid]){
                    low=mid+1;
                  if(low<nums.size())   minatleft=nums[low];
                
                }else {high=mid-1;
                 if(high>=0)   maxatright=nums[high];
                }
            }
           
        }
        return -1;
    }
};
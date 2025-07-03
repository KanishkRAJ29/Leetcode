class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        if (nums[high] != nums[high - 1])
            return nums[high];
        if (nums[0] != nums[1])
            return nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid - 1 >= 0 && nums[mid - 1] != nums[mid] && mid + 1 < n &&
                nums[mid + 1] != nums[mid]) {
                return nums[mid];

            }
            /*else if(mid%2==0&&mid-1>=0&&nums[mid-1]==nums[mid]){
                high=mid-1;
            }else low=mid;*/
            else if (mid % 2 == 0) {
                if (mid + 1 < n) {
                    if (nums[mid] == nums[mid + 1]) {
                        low = mid;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }else{
                if (mid + 1 < n) {
                    if (nums[mid] != nums[mid + 1]) {
                        low = mid;
                    }
                    else{
                        high=mid;
                    }
                }
            }
        }
        return -1;
    }
};
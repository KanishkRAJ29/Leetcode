class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void nextper(vector<int>&nums){
         int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
    string getPermutation(int n, int k) {
       vector<int>start;
        for(int i=1;i<=n;i++){
            start.push_back(i);
        }
        k--;
        
        
        while(k--){
            nextper(start);
        }
        string res="";
        for(int i=0;i<start.size();i++){
            res=res+to_string(start[i]);
        }
        return res;
    }
};
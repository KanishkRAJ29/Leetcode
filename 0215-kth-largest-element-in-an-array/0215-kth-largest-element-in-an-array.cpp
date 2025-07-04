class Solution {
public:
    int partition(vector<int>& nums, int l,int r){
        int p=nums[l];
        int i=l+1;
        int j=r;
        while(i<=j){
            if(nums[i]<p&&nums[j]>p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p)i++;
            if(nums[j]<=p)j--;
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
      int n=nums.size();
      int l=0;
      int r=n-1;
      int pivot_ind=0;
      while(true){
        pivot_ind=partition(nums,l,r);
        if(pivot_ind==k-1){
            break;
        }
        else if(pivot_ind>k-1){
          r=pivot_ind-1;  
        }
        else{
            l=pivot_ind+1;
        }
      }

      return nums[pivot_ind];
    }
};
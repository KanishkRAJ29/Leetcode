class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
       int i=0;
       int j=0;
       long long result=0;
       int pairs=0;
       int n=nums.size();
       unordered_map<int,int>mp;
       while(j<n){
        pairs+=mp[nums[j]];
        mp[nums[j]]++;
        while(pairs>=k){
            result+=n-j;
            mp[nums[i]]--;
            pairs-=mp[nums[i]];
            i++;
        }
        j++;
       } 
       return result;
    }
};
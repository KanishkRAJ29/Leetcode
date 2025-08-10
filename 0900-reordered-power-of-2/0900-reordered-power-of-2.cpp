class Solution {
public:
    bool solve(vector<int>&nums,int n){
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            string t=to_string(n);
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s==t)return true;
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        if(n==1)return true;
        if(n==0)return false;
        
        string t=to_string(n);
        sort(t.begin(),t.end());
        long long curr=0;
        for(int i=0;i<=30;i++){
            curr=(1<<i);
            string s=to_string(curr);
            
        sort(s.begin(),s.end());
            
            if(s==t)return true;
        }
        return false;
    }
};
class Solution {
public:
    int getNextIndex(vector<vector<int>>& arr,int l,int target){
        int n=arr.size();
       int r=n-1;
       int result=n+1;
       while(l<=r) {
           int mid=l+(r-l)/2;
           if(arr[mid][0]>=target){
            result=mid; 
            r=mid-1;  
           }else{
               l=mid+1;
           }
       }
       return result;
    }
    int solve(vector<vector<int>>& arr,vector<int>&memo,int i){
        int n=arr.size();
        if(i>=n){
            return 0;
        }
          if (memo[i] != -1) {
            return memo[i];
        }

        int next = getNextIndex(arr, i + 1, arr[i][1]);
        int taken = arr[i][2] + solve(arr, memo, next);
        int notTaken = solve(arr, memo, i + 1);

        memo[i] = max(taken, notTaken);
        return memo[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      int n=startTime.size();
      vector<vector<int>> arr(n,vector<int>(3,0));
      for(int i=0;i<n;i++){
        arr[i][0]=startTime[i];
        arr[i][1]=endTime[i];
        arr[i][2]=profit[i];  
      }  
      auto comp=[&](auto& vec1,auto& vec2){
          return vec1[0]<vec2[0];
      };
      sort(arr.begin(),arr.end(),comp);
      vector<int>memo(n+1,-1);
      return solve(arr,memo,0);
    }
};
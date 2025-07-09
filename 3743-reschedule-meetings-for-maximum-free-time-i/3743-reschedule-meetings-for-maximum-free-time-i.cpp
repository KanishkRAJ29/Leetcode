class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<int>gaps;
        gaps.push_back(start[0]);
        for(int i=0;i<n-1;i++){
    
            gaps.push_back(start[i+1]-end[i]);
        }
        gaps.push_back(eventTime-end[n-1]);
        int windowSize=k+1;
        int i=0;
        int j=0;
        int currSum=0;
        int maxSum=0;
        
        while(i<n-k+1&&j<n+1){
            currSum+=gaps[j];
            if(currSum>maxSum){
                maxSum=currSum; 
            }
            while(j-i==k){
                currSum-=gaps[i];
                i++;
            }
            j++;
        }
        return maxSum;
    }
};
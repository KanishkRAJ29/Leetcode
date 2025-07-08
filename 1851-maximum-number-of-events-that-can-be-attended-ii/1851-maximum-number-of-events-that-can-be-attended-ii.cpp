class Solution {
public:
int n;
vector<vector<int>>dp;
int f(vector<vector<int>>& events,int idx, int k)
{
    if(idx>=n or k==0) return 0;
    if(dp[idx][k]!=-1) return dp[idx][k];
    int start=events[idx][0];
    int end=events[idx][1];
    int value=events[idx][2];
    //skip
    int skip=f(events,idx+1,k);
    //take
    int j;
    for(j=idx+1;j<n;j++)
    {
        if(events[j][0]>events[idx][1]) break;
    }
    int take=value+f(events,j,k-1);
    return dp[idx][k]=max(skip,take);
}
    int maxValue(vector<vector<int>>& events, int k) {
     //dp.clear();
     n=events.size();
     dp.resize(n+1,vector<int>(k+1,-1));
     sort(events.begin(),events.end());
     return f(events,0,k);
    }
};
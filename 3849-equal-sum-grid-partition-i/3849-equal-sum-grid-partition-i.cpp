class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long>rowSum(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            rowSum[i]=accumulate(grid[i].begin(),grid[i].end(),0LL);
        }
        long long totalrs=accumulate(rowSum.begin(),rowSum.end(),0LL);
        long long target=totalrs/2;
        long long curr=0;
        for(int i=0;i<rowSum.size();i++){
            if(curr==totalrs-curr)return true;
            curr+=rowSum[i];
        }
        vector<long long>colSum(grid[0].size(),0);
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                colSum[j]+=grid[i][j];
            }
        }
        totalrs=accumulate(colSum.begin(),colSum.end(),0LL);
        curr=0;
        for(int i=0;i<colSum.size();i++){
            if(curr==totalrs-curr)return true;
            curr+=colSum[i];
        }
    return false;
    }
};
class Solution {
public:
    void filli(unordered_map<int,pair<int,int>>&mp, vector<vector<int>>& b){
        int first=0;
        int ind=0;
        for(int i=0;i<b.size();i++){
            first=b[i][0];
            ind=b[i][1];
            if(mp.count(first)==0){
                mp[first]={ind,ind};
            }
            else{
                if(ind<mp[first].first)mp[first].first=ind;
                else if(ind>mp[first].second)mp[first].second=ind;
            }
            
        }
        return ;
    }
     void fillj(unordered_map<int,pair<int,int>>&mp, vector<vector<int>>& b){
        int first=0;
        int ind=0;
        for(int i=0;i<b.size();i++){
            first=b[i][1];
            ind=b[i][0];
            if(mp.count(first)==0){
                mp[first]={ind,ind};
            }
            else{
                if(ind<mp[first].first)mp[first].first=ind;
                else if(ind>mp[first].second)mp[first].second=ind;
            }
            
        }
        return ;
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>mpi;
        unordered_map<int,pair<int,int>>mpj;
       // sort(buildings.begin(),buildings.end());

        filli(mpi,buildings);


       /* sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });*/
        fillj(mpj,buildings);
        int ii=0;
        int jj=0;
        int ans=0;
        for(int i=0;i<buildings.size();i++){
            ii=buildings[i][0];
            jj=buildings[i][1];
            if((jj>mpi[ii].first&&jj<mpi[ii].second)&&(ii>mpj[jj].first&&ii<mpj[jj].second)){
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
     map<int,set<int>>mp;
     for(int i=0;i<dimensions.size();i++){
        int l=dimensions[i][0];
        int r=dimensions[i][1];
        int area=l*r;
        int c=l*l+r*r;
        mp[c].insert(area);
     }   
     auto it = mp.rbegin();   // reverse iterator to last element in map
set<int>& lastSet = it->second;
return*lastSet.rbegin();

    }
};
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> um;
        for(auto i: digits){
            um[i]++;
        }
        vector<int> res;
        for(int i=100;i<999;i+=2){
            if(check(i,um)) res.push_back(i);
        }
        return res;
    }
private: 
    bool check(int n, unordered_map<int,int> um) {
        int h=n/100,t=(n/10)%10,o=n%10;
        if(um[o]){
            um[o]--;
            if(um[t]){
                um[t]--;
                if(um[h]){
                    return true;
                }
                um[t]++;
            }
            um[o]++;
        }
        return false;
    }
};
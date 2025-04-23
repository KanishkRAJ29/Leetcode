class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int key=0;
            int j=i;
            while(j){
                key+=j%10;
                j/=10;
            }
            mp[key]++;
            maxi=max(maxi,mp[key]);
             
        
        }
        int count = 0;
        for (auto& [_, value] : mp) {
            if (value == maxi) {
                ++count;
            }
        }
        return count;
    }
};
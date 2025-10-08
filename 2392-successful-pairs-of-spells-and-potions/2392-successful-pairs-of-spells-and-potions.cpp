
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>product;
        for(int i=0;i<n;i++){
            int s=0;
            int e=potions.size()-1;
            int ans=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                long long value=(long)potions[mid]*spells[i];
                if(value>=success){
                    ans=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }
            if(ans!=-1){
                product.push_back(potions.size()-ans);
            }
            else product.push_back(0);
            
        }
        return product;
    }
};
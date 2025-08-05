class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        for(int i=0;i<fruits.size();i++){
            int n=baskets.size();
            int j=0;
            while(j<baskets.size()){
                if(baskets[j]>=fruits[i]){
                    baskets.erase(baskets.begin()+j);
                    break;
                }
                else{
                    j++;
                }
            }
            if(baskets.size()==n)count++;
        }
        return count;
    }
};
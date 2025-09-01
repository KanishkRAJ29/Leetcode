class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,i=1,buy=-1;
        while(i<prices.size()){
            if(buy==-1){
                while(i<prices.size() && prices[i-1]>=prices[i]){
                    i++;
                }
                if(i!=prices.size()) buy=prices[i-1];
            }
            else{
                while(i<prices.size() && prices[i-1]<=prices[i]){
                    i++;
                }
                profit+=prices[i-1]-buy;
                buy=-1;
            }
        }
        return profit;
    }
};
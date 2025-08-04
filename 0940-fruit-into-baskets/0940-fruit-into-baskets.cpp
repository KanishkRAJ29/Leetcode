class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>basket;
        int i=0;
        int j=0;
        int maxi=0;
    while(j<fruits.size()){
        if(basket.size()<2||basket.count(fruits[j])!=0){
            basket[fruits[j]]++;
            j++;
            int curr=0;
            /*for(auto &[key,val]:basket){
                curr+=val;
            }**/ curr=j-i;
            maxi=max(curr,maxi);
        }else{
            while(i<=j&&basket.size()==2){
                basket[fruits[i]]--;
                if(basket[fruits[i]]==0)basket.erase(fruits[i]);
                i++;
            }
        }
        
    }
    return maxi;

    }
};
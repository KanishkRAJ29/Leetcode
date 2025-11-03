class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total=0;
        int prev=neededTime[0];
        char pc=colors[0];
        for(int i=1;i<colors.size();i++){
            if(pc==colors[i]){
                total+=min(neededTime[i],prev);
                prev=max(neededTime[i],prev);
            }else{
                prev=neededTime[i];
                pc=colors[i];
            }
        }
        return total;
    }
};
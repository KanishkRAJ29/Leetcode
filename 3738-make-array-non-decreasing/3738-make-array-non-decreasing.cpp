class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        for(int num:nums){
            int maxi=num;
            while(!st.empty()&&maxi<st.top()){
                maxi=max(maxi,st.top());
                st.pop();
            }
            
                st.push(maxi);
            
        }
        return st.size();
    }
};
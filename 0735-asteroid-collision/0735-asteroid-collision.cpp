class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){st.push(nums[i]);
            }
            else{
                int h=-nums[i];
                int eq=0;
                while(!st.empty()&&st.top()<=h){
                    if(st.top()==h)eq=1;
                    st.pop();
                    if(eq==1)break;
                }
                if(st.empty()&&eq==0){
                    ans.push_back(nums[i]);
                }
            }
        }
        int j=ans.size();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin()+j,ans.end());
        return ans;
    }
};
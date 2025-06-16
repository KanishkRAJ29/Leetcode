class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        sort(queries.begin(),queries.end());
        priority_queue<int>ending;
        priority_queue<int,vector<int>,greater<int>>past;
        int j=0;
        int usecount=0;
        for(int i=0;i<n;i++){
            while(j<q&&queries[j][0]==i){
                ending.push(queries[j][1]);
                j++;
            }
            nums[i]-=past.size();
            while(nums[i]>0&&!ending.empty()&&ending.top()>=i){
                int end=ending.top();
                ending.pop();
                usecount++;
                nums[i]--;
                past.push(end);
            }
            if(nums[i]>0)return -1;
            while(!past.empty()&&past.top()<=i){
                past.pop();
            }
        }
        return q-usecount;
    }
};
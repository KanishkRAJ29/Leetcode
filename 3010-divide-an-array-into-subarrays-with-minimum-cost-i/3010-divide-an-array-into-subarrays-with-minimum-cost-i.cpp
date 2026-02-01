class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int>pq;
        for (int i = 1; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if (pq.size() > 2) {
                pq.pop();
            }
        }
        int one=pq.top();
        pq.pop();
        return nums[0]+one+pq.top();
    }
};
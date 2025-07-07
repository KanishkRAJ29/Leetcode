class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftSmall(heights.size(), 0);
        vector<int> rightSmall(heights.size(), 0);
        stack<int> st;
        
        // Compute leftSmall
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            leftSmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Compute rightSmall
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            rightSmall[i] = st.empty() ? heights.size() - 1 : st.top() - 1;
            st.push(i);
        }

        // Calculate max area
        int maxA = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }

        return maxA;
    }
};

class Solution {
public:
    int largestHisto(vector<int>&h,int n){
        stack<int>st;
        int maxArea=0;
        int currArea;
        for(int i=0;i<n;i++){
            if(st.empty()||h[i]>h[st.top()]){
                st.push(i);
                continue;
            }else{
                while(!st.empty()&&h[i]<=h[st.top()]){
                    int rightSmall=i;
                    int height=h[st.top()];
                    st.pop();
                    int leftSmall=(!st.empty())?st.top():-1;
                    currArea=height*(rightSmall-leftSmall-1);

                    maxArea=max(maxArea,currArea);
                }

            }
            
            
            
            st.push(i);
        }
        while(!st.empty()){
                    int rightSmall=n;
                    int height=h[st.top()];
                    st.pop();
                    int leftSmall=(!st.empty())?st.top():-1;
                    currArea=height*(rightSmall-leftSmall-1);

                    maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0); 
        int maxArea = 0;
        
        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
          
            int n = heights.size(); 
            int currArea=largestHisto(heights,n);
            maxArea=max(maxArea,currArea);
        }
        
        return maxArea;
    }
};
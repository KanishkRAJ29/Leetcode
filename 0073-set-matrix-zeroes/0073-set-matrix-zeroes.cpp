class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool frow = false, fcol = false;

        // Check if first column should be zero
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0) fcol = true;
        }

        // Check if first row should be zero
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0) frow = true;
        }

        // Use first row and column as markers
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on markers
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first column
        if(fcol){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }

        // Handle first row
        if(frow){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
    }
};

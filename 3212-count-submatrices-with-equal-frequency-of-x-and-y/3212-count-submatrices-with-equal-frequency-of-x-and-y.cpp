class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // Use stack-allocated array for faster performance and lower memory footprint
        array<pair<int, int>, 1000> row{};
        const int m = grid.size(), n = grid[0].size();
        
        // Initialize the first cell
        char c = grid[0][0];
        row[0].first += (c == 'X');
        row[0].second += (c == 'Y');
        int ans = 0;
        
        // Process the rest of the first row
        for (int j = 1; j < n; j++) {
            char c = grid[0][j];
            row[j].first = row[j - 1].first + (c == 'X');
            row[j].second = row[j - 1].second + (c == 'Y');
            
            // Check condition: at least one 'X' and equal 'X' and 'Y'
            if (row[j].first > 0 && row[j].first == row[j].second)
                ans++;
        }
        
        // Process the remaining rows
        for (int i = 1; i < m; i++) {
            // 'now' tracks the prefix sum of 'X' and 'Y' for the current row
            pair<int, int> now{};
            
            // Process the first column of the current row
            char c = grid[i][0];
            row[0].first += now.first = (c == 'X');
            row[0].second += now.second = (c == 'Y');
            if (row[0].first > 0 && row[0].first == row[0].second)
                ans++;
                
            // Process the rest of the current row
            for (int j = 1; j < n; j++) {
                char c = grid[i][j];
                // Compact update: add to current row ('now') and then to overall column ('row')
                row[j].first += now.first += (c == 'X');
                row[j].second += now.second += (c == 'Y');
                
                // Check if the submatrix from (0,0) to (i,j) is valid
                if (row[j].first > 0 && row[j].first == row[j].second)
                    ans++;
            }
        }
        return ans;
    }
};
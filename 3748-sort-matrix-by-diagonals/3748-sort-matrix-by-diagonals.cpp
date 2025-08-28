class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
     int i=0;
     int j=0;

    // diagonals starting from first column (descending)
    for(int i=0;i<grid.size();i++){
        j=0;  // was j=i
        int row=i;
        int col=j;
        vector<int>diag;
        while(row<grid.size()&&col<grid[0].size()){      // use col, not j
            diag.push_back(grid[row][col]);
            row++;
            col++;
        }
        sort(diag.begin(),diag.end());
        reverse(diag.begin(),diag.end());
        row=i; col=j;                                     // reset both
        int cur=0;
        while(row<grid.size()&&col<grid[0].size()){       // use col, not j
            grid[row][col]=diag[cur];
            cur++;
            row++;
            col++;
        }
    }

    // diagonals starting from top row (ascending)
    for(int j=1;j<grid[0].size();j++){
        i=0;  // was i=j
        int row=i;
        int col=j;
        vector<int>diag;
        while(row<grid.size()&&col<grid[0].size()){
            diag.push_back(grid[row][col]);               // use row, not i
            col++;
            row++;
        }
        sort(diag.begin(),diag.end());                    // ascending
        row=i; col=j;                                     // reset both
        int cur=0;
        while(row<grid.size()&&col<grid[0].size()){       // use col, not j
            grid[row][col]=diag[cur];
            cur++;
            row++;
            col++;
        }
    }
    return grid;
    }
};

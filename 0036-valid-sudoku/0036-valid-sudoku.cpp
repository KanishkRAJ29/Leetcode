class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int num=9;
        bool row[num][num]={false};
        bool column[num][num]={false};
        bool grid[num][num]={false};
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(board[i][j]=='.')continue;
                int gridNo = (i/3)*3+(j/3);
                int idx=board[i][j]-'0'-1;
                if(row[i][idx]||column[j][idx]||grid[gridNo][idx]){
                    return false;
                }
                row[i][idx]=true;
                column[j][idx]=true;
                grid[gridNo][idx]=true;
            }
        }
        return true;
    }
};
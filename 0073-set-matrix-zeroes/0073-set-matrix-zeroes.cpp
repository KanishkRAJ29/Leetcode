class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool firstrowzero=false;
        bool firstcolzero=false;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                firstcolzero=true;
                break;
            }
        }
           for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                firstrowzero=true;
                break;
            }
        }
        //first row and first col use as an indentify that which row and col has to be zero
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
               if(matrix[i][j]==0){
                   matrix[0][j]=0;
                   matrix[i][0]=0;
               }
            }
        }
        // now make changes in matrix and make  row and col as zero acc to first row and col
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }

        // now check for first row and col 
        if(firstrowzero){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcolzero){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};/*class Solution {
public:
   void makecolumnzero(vector<vector<int>>& matrix,int j){
        for(int i=0;i<matrix.size();i++){
          if(matrix[i][j]!=6969) { matrix[i][j]=0;}
        }
    }
       void makerowzero(vector<vector<int>>& matrix,int i){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]!=6969) { matrix[i][j]=0;}
        }
    }
  

    void setZeroes(vector<vector<int>>& matrix) {
    
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                matrix[i][j]=6969;
            }
        }}
        for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==6969){
                makerowzero(matrix,i);
                makecolumnzero(matrix,j);
            }
        }

       } 
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==6969){
                matrix[i][j]=0;
            }
        }}

    }
};
*/


 /* void setZeroes(vector<vector<int>>& matrix) {
       vector<pair<int,int>>ind;
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                ind.push_back(make_pair(i,j));
            }
        }

       } 
       for(int i=0;i<ind.size();i++){
        makerowzero(matrix,ind[i].first);
        makecolumnzero(matrix,ind[i].second);
       }

    }
};*/
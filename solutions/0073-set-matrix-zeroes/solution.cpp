class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int c0=1;
        //mark rows and columns to be made zero
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    if(i==0){
                        c0=0;
                    }
                    else
                    matrix[i][0]=0;
                }
            }
        }
        //turn (1,1) to (m-1,n-1) to zero
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        //mark first column
        if(matrix[0][0]==0){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }
        //mark first row
        if(c0==0){
            for(int j=0; j<n; j++){
                matrix[0][j]=0;
            }
        }
    }
};

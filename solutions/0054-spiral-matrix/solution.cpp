class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();//no. of rows
        int n=matrix[0].size();//no. of columns
        vector <int> res;

        // initialize the boundaries
        int top=0,right=n-1,bottom=m-1,left=0;

        while(left<=right && top<=bottom){
            //traverse top row
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            //traverse right column
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            //traverse bottom column if top<bottom
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //traverse left column if left<right
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

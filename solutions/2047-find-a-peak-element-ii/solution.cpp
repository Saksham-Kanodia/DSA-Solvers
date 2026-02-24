class Solution {
public:

int maxRow(vector<vector<int>>& mat, int midCol){
    int maxIdx = 0;

    for(int i=0; i<mat.size(); i++){
        if(mat[i][midCol]>mat[maxIdx][midCol]){
            maxIdx =i;
        }
    }
    
    return maxIdx;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low =0;
        int high = cols-1;

        while(low<=high){
            int midCol = low + (high - low)/2;

            int maxR = maxRow(mat,midCol);

            int left = (midCol>0) ? mat[maxR][midCol-1] : INT_MIN;
            int right = (midCol<cols-1) ? mat[maxR][midCol+1] :INT_MIN;

            if(mat[maxR][midCol]>=left && mat[maxR][midCol]>=right)
            return {maxR,midCol};

            else if(left>mat[maxR][midCol])
            high = midCol-1;

            else 
            low = midCol +1;

        }

        return {-1,-1};
    }
};

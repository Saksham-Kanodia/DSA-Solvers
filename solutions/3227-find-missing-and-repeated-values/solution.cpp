class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long rows =grid.size();
        long long cols = grid[0].size();
        long long n=(rows*cols);
        long long Sn=(n*(n+1))/2;
        long long Sn2=(n*(n+1)*(2*n+1))/6;
        long long S=0,S2=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                S+=grid[i][j];
                S2+=((long long)grid[i][j]*grid[i][j]);
            }
        }
        long long val1=S-Sn;
        long long val2=S2-Sn2;
        val2/=val1;
        long long x=(val1+val2)/2;
        long long y=val2-x;
        return {(int)x,(int)y};
    }
};

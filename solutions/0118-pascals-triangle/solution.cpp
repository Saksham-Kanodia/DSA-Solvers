class Solution {
public:

vector <int> generateRow(int rows){
    //declare the ans row list
    vector <int> ansRow;
    int ans=1;
    ansRow.push_back(ans);
    for(int cols=1; cols<rows; cols++){
        ans*=(rows-cols);
        ans/=cols;
        ansRow.push_back(ans);
    }
    return ansRow;
}
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

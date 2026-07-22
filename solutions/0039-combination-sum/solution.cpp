class Solution {
public:

void combSum(int idx, vector <int> &ds, int target, vector<int> &candidates, vector<vector<int>> &ans){

    if(idx>=candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(candidates[idx]<=target){
        ds.push_back(candidates[idx]);
        combSum(idx, ds, target - candidates[idx], candidates, ans);
        ds.pop_back();
    }

    combSum(idx+1, ds, target, candidates, ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> ds;
        vector <vector<int>> ans;

        combSum(0, ds, target, candidates, ans);

        return ans;
    }
};

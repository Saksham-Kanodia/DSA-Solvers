#include <bits/stdc++.h>
using namespace std;

//Combination Sum-2 leetcode 40      

void combinationSum2(int idx, vector <int> &ds, int target, vector <int> &candidates, set<vector<int>> &ans, int n){

    if(idx>=n){
        if(target==0){
            ans.insert(ds);
        }
        return;
    }

    if(candidates[idx]<=target){
        ds.push_back(candidates[idx]);
        combinationSum2(idx+1, ds, target-candidates[idx], candidates, ans, n);
        ds.pop_back();
    }

    combinationSum2(idx+1, ds, target, candidates, ans, n);

}

int main(){

    vector <int> candidates = {10,1,2,7,6,1,5};
    int target =8;

    set<vector<int>> ans;
    vector <int> ds;
    int n= candidates.size();

    combinationSum2(0, ds, target, candidates, ans, n);

    for(auto it: ans){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

void combSum(int idx, vector <int> &ds, int target, int arr[], vector <vector <int>> &ans, int n){
    if(idx>=n){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[idx]<=target){
        ds.push_back(arr[idx]);
        combSum(idx, ds, target-arr[idx], arr, ans,n);
        ds.pop_back();
    }

    combSum(idx+1, ds, target, arr, ans,n);
}

int main(){
    
    int arr[] = {2,3,6,7};
    int target = 7;
    vector <int> ds;

    vector <vector<int>> ans;
    int n = sizeof(arr)/sizeof(arr[0]);

    combSum(0, ds, target, arr, ans, n);

    for(auto it: ans){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

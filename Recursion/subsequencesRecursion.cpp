#include <bits/stdc++.h>
using namespace std;

bool printF(int idx, vector <int> &ds, int sum,int target, int arr[], int n){
    if(idx>=n){
        if(sum==target){
            for(auto it: ds){
            cout << it << " ";
        }
        if(ds.size()==0){
        cout << "{}" << endl;
        }
        cout << endl;
        return true;
        }

        return false;
    }
    
    ds.push_back(arr[idx]);
    sum+=arr[idx];

    if(printF(idx+1, ds, sum, target, arr, n)) return true;

    ds.pop_back();
    sum-=arr[idx];

   if(printF(idx+1, ds, sum, target,arr, n)) return true;

   return false;
}

int main(){

    int arr[] = {3,1,2,4};
    vector <int> ds;
    int sum =0;
    int target = 3;
 
    printF(0, ds,sum,target, arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
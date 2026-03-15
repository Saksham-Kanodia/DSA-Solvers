#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TIME Complexities:- O(n*logn)
//Space Complexity:- O(1)

void merge(vector <int> &arr, int low, int mid, int high){
    vector <int> temp;
    int n1 = mid;
    int n2 = high;

    int i=low;
    int j=mid+1;

    while(i<=n1 && j<=n2){
        if(arr[i]<arr[j])
        temp.push_back(arr[i++]);
        else 
        temp.push_back(arr[j++]);
    } 

    while(i<=n1)
    temp.push_back(arr[i++]);

    while(j<=n2)
    temp.push_back(arr[j++]);

    //copy these elements back into original array
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }

}

void mergeSort(vector <int> &arr, int low, int high){
    if(low>=high) return;

    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void printArray(vector <int> &arr){
    for(int val:arr){
        cout << val << " ";
    }
}


int main(){
    vector <int> arr = {64,25,12,22,11};
    int n=arr.size();

    cout << "Original Array: ";
    printArray(arr);

    mergeSort(arr,0,n-1);

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
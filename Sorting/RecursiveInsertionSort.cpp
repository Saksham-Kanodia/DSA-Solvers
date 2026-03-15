#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursiveInsertionSort(vector <int> &arr, int n){
    if(n<=1) return; //base case if array size get to 1, it is sorted so return.
    
    recursiveInsertionSort(arr,n-1);

    int key = arr[n-1];
    int j=n-2;

    while(j>=0 && arr[j]>=key){
        arr[j+1]=arr[j];
        j--;
    }

    arr[j+1]=key;
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

    recursiveInsertionSort(arr,n);

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}

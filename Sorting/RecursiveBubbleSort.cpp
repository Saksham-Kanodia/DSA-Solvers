#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursiveBubbleSort(vector <int> &arr,int n){
    if(n==1) return; //Base Case: if array size is 1 means all are sorted now, so return.

    //one pass of bubble sort which sorts the largest element
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }

    //Recursive bubble sort for the remaining array.
    return recursiveBubbleSort(arr,n-1);

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

    recursiveBubbleSort(arr,n);

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
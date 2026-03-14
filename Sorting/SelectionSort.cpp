#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector <int> &arr){
    int n=arr.size();

    for(int i=0; i<n; i++){
        //Take the current 
        int min_idx = i;
    }
}

void printArray(vector <int> &arr){
    for(int val:arr){
        cout << val << " ";
    }
}


int main(){
    vector <int> arr = {64,25,12,22,11};

    cout << "Original Array: ";
    printArray(arr);

    cout << "Sorted Array: ";
    printArray(arr);

}
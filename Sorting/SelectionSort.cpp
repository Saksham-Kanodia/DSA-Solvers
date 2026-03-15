#include <iostream>
#include <vector>
using namespace std;

//Time Complexity:- O(n^2)
//Space Complexity:- O(1)

void selectionSort(vector <int> &arr){
    int n=arr.size();

    for(int i=0; i<n; i++){
        //Take the current 
        int min_idx = i;

        //look for minimum elemnt in unsorted part.
        for(int j=i+1; j<n; j++){

            //update the minimum index.
            if(arr[j]<arr[min_idx])
            min_idx=j;
        }

        //swap current element and min_index element.
        swap(arr[i],arr[min_idx]);
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

    selectionSort(arr);

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
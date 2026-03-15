#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This function finds the pivot and places it correctly
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; // Picking the first element as pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Move i forward until you find an element > pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Move j backward until you find an element < pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    // Swap pivot into its final resting place
    swap(arr[low], arr[j]);
    return j; // Return the partition index
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1); // Left half
        quickSort(arr, partitionIndex + 1, high); // Right half
    }
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

    quickSort(arr,0,n);

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
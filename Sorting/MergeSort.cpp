# include <iostream>
# include <vector>
using namespace std;

void merge(vector <int> &arr, int low, int mid , int high){

    vector <int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else if(arr[left]>arr[right]){
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            temp.push_back(arr[right]);
            left++; right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }//explanation: i-low is used to get index of temp array as temp array starts from 0 index and not low index.

}

void mergeSort(vector <int> &arr, int low, int high){
    if(low == high) return;

    int mid = (low+high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr,low,mid,high);
}

void printArray(vector <int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] <<" ";
    }
}

int main(){

    vector <int> arr = {3,1,2,4,1,5,2,6,4};

    cout << "Original Array: ";
    printArray(arr);

    cout << "New Array after Merge Sort: ";
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);


    return 0;
}
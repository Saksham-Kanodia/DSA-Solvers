# include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute Logic - Flatten the matrix into 1D array and then find median.
//Time Complexity- O(n*m) as traversing entire matrix to copy elements.
//Space Complexity- O(n*m) as storing in new 1D array.
int bruteForce(vector <vector<int>> &mat){
    vector <int> arr;
    int rows = mat.size();
    int cols= mat[0].size();

    //copying the elements
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            arr.push_back(mat[i][j]);
        }
    }

    //sorting the array to find median
    sort(arr.begin(),arr.end());

    //finding median index 
    int mid = (rows*cols)/2;
    int median = arr[mid];

    return median;
}

//Optimal Logic- Use Binary Search on Answer.
/*The key idea is that for a number x to be the median in an n x m matrix, there must be exactly (n * m) / 2 elements less than or equal to x. 
We perform binary search over the range [minElement, maxElement], where minElement and maxElement are the smallest and largest elements in the matrix.
At each step, we compute the number of elements less than or equal to the current mid.
=> If this count is less than or equal to (n * m) / 2, we search in the upper half of the range to increase the candidate value.
=> Otherwise, we search in the lower half to reduce it*/

//Time Complexity:- O(n*log(MaxElement))
//Space Complexity:- O(1)
int countLessEqual(vector <vector<int>> &mat, int mid){
    int count=0;
    int n= mat.size();

    for(int i=0; i<n; i++){
        count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    }

    return count;

}

int optimalSolution(vector <vector<int>> &mat){
    
    int n = mat.size();//n rows
    int m = mat[0].size();//m columns

    int low = 1e9, high =-1e9;
    for(int i=0; i<n; i++){
        low = min(low,mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    int ans =low;
    int requiredCount =(n*m)/2;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(countLessEqual(mat,mid)> requiredCount){
            ans = mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }

    return ans;

}

int main(){
    vector <vector<int>> mat={{1,3,5},
                              {2,6,9},
                              {3,6,9}};

    cout << "Median: " << bruteForce(mat) << endl;
    cout << "Median: " << optimalSolution(mat) << endl;

    return 0;
}
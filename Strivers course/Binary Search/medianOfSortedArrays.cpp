# include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION - O(n1+n2) Time Complexity and O(n1+n2) Space Complexity
vector <int> mergedArray(vector <int> &nums1, vector <int> &nums2){

    vector <int> mergedArr;
    int n1 = nums1.size();
    int n2 = nums2.size();

    int i=0,j=0;

    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            mergedArr.push_back(nums1[i]);
            i++;
        }
        else if(nums2[j]<nums1[i]){
            mergedArr.push_back(nums2[j]);
            j++;
        }
        else{
            mergedArr.push_back(nums1[i]);
            mergedArr.push_back(nums2[j]);
            i++; j++;
        }
    }
    while(i<n1){
        mergedArr.push_back(nums1[i]);
        i++;
    }
    while(j<n2){
        mergedArr.push_back(nums2[j]);
        j++;
    }

    return mergedArr;
}

double findMedianOfSortedArrays(vector <int> &nums1, vector <int> &nums2){

    vector <int> nums = mergedArray(nums1, nums2);
    int n= nums.size();

    if(n%2 != 0) return nums[(n-1)/2];
    else{
        double median = (nums[(n-1)/2] + nums[n/2])/2.0;
        return median;
    }
}

//BETTER APPROACH- merge of merge sort approach
//O(n1 + n2) time complexity as in worst case scenario of both duplicates, both pointers will move.
// O(1) space.

double medianOfSortedArrays(vector <int> &nums1, vector <int> &nums2){

    int n1=nums1.size();
    int n2=nums2.size();
    int total = n1+n2;
    int prev=0,curr=0;

    int i=0,j=0;
    int count=0;

    while(count <= total/2){
        prev=curr;

        if(i<n1 && (j>=n2 || nums1[i]<=nums2[j])){
            curr = nums1[i];
            i++;
        }
        else{
            curr = nums2[j];
            j++;
        }

        count++;
    }

    if(total%2 != 0) return curr;
    else return (prev + curr)/2.0;

}

//Binary Search - Partition method
//O(log(min(n1,n2))) Time Complexity
//O(1) Space Complexity.

double medianSortedArrays(vector <int> &nums1, vector <int> &nums2){

    if(nums1.size()>nums2.size())
    return medianSortedArrays(nums2,nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low=0;
    int high=n1;

    while(low<=high){
        int i= (low+high)/2;
        int j = (n1+n2+1)/2-i;

        int leftA = (i==0) ? INT_MIN : nums1[i-1];
        int rightA = (i==n1) ? INT_MAX : nums1[i];

        int leftB = (j==0) ? INT_MIN : nums2[j-1];
        int rightB = (j==n2) ? INT_MAX : nums2[j];

        if(leftA<=rightB && leftB<=rightA){
            if((n1+n2)%2 != 0) return max(leftA,leftB);
            else{
                return (max(leftA,leftB)+min(rightA,rightB))/2.0;
            }
        }
        else if(leftA>rightB)
        high = i-1;
        else
        low=i+1; 
    }

    return -1;
}

int main(){

    int n1,n2;
    vector <int> nums1,nums2;

    cout << "Enter no. of first array Elements: ";
    cin >> n1;

    cout << "Enter no. of second array Elements: ";
    cin >> n2;

    cout << "Enter first array elements: ";
    for(int i=0; i<n1; i++){
        int num;
        cin >> num;
        nums1.push_back(num);
    }

    cout << "Enter second array elements: ";
    for(int i=0; i<n2; i++){
        int num;
        cin >> num;
        nums2.push_back(num);
    }

    cout << "Median of sorted arrays: " << findMedianOfSortedArrays(nums1,nums2);
    
    return 0;
}
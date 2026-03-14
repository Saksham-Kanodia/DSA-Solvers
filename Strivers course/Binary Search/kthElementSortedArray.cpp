# include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION- CREATING MERGED ARRAY.
//TIME COMPLEXITY - O(n1+n2) 
//SPACE COMPLEXITY- O(n1+n2)

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

int findKthElementOfSortedArray(vector <int> &nums1, vector <int> &nums2, int k){

    int n1 = nums1.size();
    int n2= nums2.size();

    vector <int> nums = mergedArray(nums1,nums2);
    return nums[k-1];

}

//BETTER SOLUTION- MERGE OF MERGE SORT
//TIME COMPLEXITY - O(n1+n2)
//SPACE COMPLEXITY - O(1)

int findKthElementOfSortedArray2(vector <int> &nums1, vector <int> &nums2, int k){

    int n1 = nums1.size();
    int n2 = nums2.size();

    int i=0,j=0,total=n1+n2;
    int count=0;
    int curr=0;

    while(count < k){

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

    return curr;
}

//USING BINARY SEARCH - O(log(min(n1,n2))) Time Complexity and O(1) space.

int findKthElementOfSortedArray3(vector <int> &nums1, vector <int> &nums2, int k){

    if(nums1.size()>nums2.size())
    return findKthElementOfSortedArray3(nums2,nums1,k);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low =0;
    int high = n1;

    while(low<=high){
        int i= (low + high)/2;
        int j= k -i;

        int leftA = (i==0) ? INT_MIN : nums1[i-1];
        int rightA = (i==n1) ? INT_MAX : nums1[i];

        int leftB = (j==0) ? INT_MIN : nums2[j-1];
        int rightB = (j==n2) ? INT_MAX : nums2[j];

        if(leftA<=rightB && leftB<=rightA){
            return max(leftA,leftB);
        }

        else if(leftA>rightB)
        high = i-1;

        else 
        low =i+1;
    }

    return -1;
}

int main(){

    int n1,n2,k;
    vector <int> nums1,nums2;

    cout << "Enter no. of first array elements: ";
    cin >> n1;

    cout << "Enter no. of second array elements: ";
    cin >> n2;

    for(int i=0; i<n1; i++){
        int num;
        cin >> num;
        nums1.push_back(num);
    }
    
    for(int i=0; i<n2; i++){
        int num;
        cin >> num;
        nums2.push_back(num);
    }

    cout << "Enter the Kth position(1-based indexing): ";
    cin >> k;

    cout << "Kth element of 2 sorted arrays is: " << findKthElementOfSortedArray3(nums1,nums2,k);

    return 0;
}
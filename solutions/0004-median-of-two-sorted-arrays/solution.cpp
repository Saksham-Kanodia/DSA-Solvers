class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
    return findMedianSortedArrays(nums2,nums1);

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
};

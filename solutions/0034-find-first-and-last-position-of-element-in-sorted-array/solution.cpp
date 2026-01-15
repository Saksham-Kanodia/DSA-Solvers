class Solution {
public:

int firstAndLast(vector<int> &nums, int target, bool findFirst){
    int n=nums.size();
    int ind=-1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target){
            ind=mid;
            if(findFirst==true) high=mid-1;
            else low=mid+1;
        }

        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return ind;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstAndLast(nums,target,true);
        int last=firstAndLast(nums,target,false);

        return {first,last};
    }
};

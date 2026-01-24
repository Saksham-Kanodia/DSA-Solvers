class Solution {
public:

    bool check(vector<int>& nums, int threshold, int div){
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=(nums[i]+div-1)/div;
        }
        return (sum<=threshold);
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int res=high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,threshold,mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};

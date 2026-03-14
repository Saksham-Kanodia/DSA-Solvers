class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2!=0) continue;
            int cnt=1;
            for(int j=0; j<n; j++){
                if(nums[j]==nums[i] && j!=i) cnt++;
            }
            if(cnt==1) return nums[i];
        }
        return -1;
    }
};

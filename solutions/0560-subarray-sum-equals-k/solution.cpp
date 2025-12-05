class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int,int> map;
        map[0]=1;
        int prefixSum=0,count=0;
        //traverse the map;
        for(int i=0; i<n; i++){
            prefixSum+=nums[i];
            count += map[prefixSum-k];
            map[prefixSum]+=1;
        }
        return count;
    }
};

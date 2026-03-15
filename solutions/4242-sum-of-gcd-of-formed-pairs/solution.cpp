class Solution {
public:

    int findGCD(int num1, int num2){
        if(num1>num2) return findGCD(num2,num1);
        if(num1==1)
            return 1;
        if(num2%num1==0)
            return num1;
        else
            return findGCD(num2%num1,num1);
    }
    
    long long gcdSum(vector<int>& nums) {
        vector <int> prefixGCD;
        int mxi=nums[0];

        for(int i=0; i<nums.size(); i++){
            mxi = max(mxi,nums[i]);
            int prefixGcd = findGCD(nums[i],mxi);
            prefixGCD.push_back(prefixGcd);
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        
        long long GCDSum=0;
        int left=0,right=prefixGCD.size()-1;
        while(left<right){
            GCDSum+=findGCD(prefixGCD[left],prefixGCD[right]);
            left++;
            right--;
        }

        return GCDSum;
    }
};

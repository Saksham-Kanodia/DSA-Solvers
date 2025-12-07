class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1=-1,ele2=-1,cnt1=0,cnt2=0;
        for(int i=0; i<n; i++){
            //increment count1
            if(nums[i]==ele1)
                cnt1++;
            //increment count2
            else if(nums[i]==ele2)
                cnt2++;
            //if count1 goes to 0 update element
            else if(cnt1==0){
                cnt1=1;
                ele1=nums[i];
            }
            //if count2 goes to 0 update element
            else if(cnt2==0){
                cnt2=1;
                ele2=nums[i];
            }
            else{
                cnt1--; cnt2--;
            }
        }
        
        vector <int> res;
        cnt1=0;
        cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        if(cnt1>(n/3)) res.push_back(ele1);
        if(cnt2 > n/3 && ele1!=ele2) res.push_back(ele2);

        return res;
    }
};

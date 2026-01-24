class Solution {
public:
    bool check(vector<int>& piles, int h, int speed){
        long long req_time=0;

        for(int i=0; i<piles.size(); i++){
            req_time+=(piles[i]+speed-1)/speed;
        }

        return req_time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int res = high;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(check(piles,h,mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};

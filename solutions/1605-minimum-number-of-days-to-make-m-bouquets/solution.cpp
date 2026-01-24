class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int days){
        int cnt=0;
        int bouquets=0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=days){
                cnt++;
            }
            else{
                bouquets+=cnt/k;
                cnt=0;
            }
        }

        bouquets+=cnt/k;

        return (bouquets>=m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1, high=*max_element(bloomDay.begin(),bloomDay.end());
        int res = -1;

        while(low<=high){
            int d= low +(high-low)/2;

            if(check(bloomDay,m,k,d)){
                res=d;
                high=d-1;
            }
            else low = d+1;
        }

        return res;
    }
};

class Solution {
public:
    bool check(vector<int>& weights, int days, int cap){
        int n=weights.size();
        int d=1;
        int currLoad=0;
        for(int i=0; i<n; i++){
            if(currLoad+weights[i]<=cap)
            currLoad+=weights[i];
            else{
                d++;
                currLoad=weights[i];
            }
        }
        return (d<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high = 0;
        for(int i=0; i<n; i++){
            high+=weights[i];
        }
        int minCap=low;

        while(low<=high){
            int cap = low + (high-low)/2;

            if(check(weights,days,cap)){
                minCap=cap;
                high = cap-1;
            }
            else low=cap+1;
        }

        return minCap;
    }
};

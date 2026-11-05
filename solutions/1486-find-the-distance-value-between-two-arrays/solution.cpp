class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt =0;
        int n1 = arr1.size();
        int n2 = arr2.size();

        for(int i=0; i<n1; i++){
            bool found = true;
            for(int j=0; j<n2; j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    found = false;
                    break;
                }
            }
            if(found)
            cnt++;
        }

        return cnt;
    }
};

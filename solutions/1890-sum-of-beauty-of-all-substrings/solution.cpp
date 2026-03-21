class Solution {
public:

    int beautySum(string s) {
        int n=s.length();
        int beautySum=0;

        for(int i=0; i<n; i++){
            unordered_map <char,int> mpp;

            for(int j=i; j<n; j++){
                mpp[s[j]]++;

                int max_freq = INT_MIN;
                int min_freq= INT_MAX;

                for(auto& it:mpp){
                    max_freq=max(max_freq,it.second);
                    min_freq=min(min_freq,it.second);
                }

                beautySum+=(max_freq-min_freq);
            }
        }

        return beautySum;
    }
};

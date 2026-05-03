class Solution {
public:
    int numSplits(string s) {
        vector <int> left(26,0),right(26,0);
        int ans=0;

        for(char c:s){
            right[c-'a']++;
        }

        int leftDistinct =0;
        int rightDistinct =0;

        for(int i=0; i<26; i++){
            if(right[i]>0) rightDistinct++;
        }

        for(int i=0; i<s.length()-1; i++){
            int idx = s[i]-'a';

            right[idx]--;
            if(right[idx]==0) rightDistinct--;

            left[idx]++;
            if(left[idx]==1) leftDistinct++;

            if(leftDistinct==rightDistinct) ans++;
        }

        return ans;
    }
};

class Solution {
public:
    int partitionString(string s) {
        vector <bool> seen(26,0);
        int ans=1;

        for(char c:s){
            if(seen[c-'a']){
                ans++;
                fill(seen.begin(), seen.end(), false);
            }

            seen[c-'a']=true;
        }

        return ans;

    }
};

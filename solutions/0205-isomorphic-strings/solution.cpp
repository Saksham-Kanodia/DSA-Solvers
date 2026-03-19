class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        unordered_map <char,int> mpp1,mpp2;

        for(int i=0; i<n; i++){
            
            if(mpp1.find(s[i])==mpp1.end())
            mpp1[s[i]]=i;

            if(mpp2.find(t[i])==mpp2.end())
            mpp2[t[i]]=i;

            if(mpp1[s[i]]!=mpp2[t[i]])
            return false;
        }

        return true;
    }
};

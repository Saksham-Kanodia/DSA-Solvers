class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;

        unordered_map <char,int> mpp;

        for(char ch:s)
        mpp[ch]+=1;

        for(char ch:t)
        mpp[ch]-=1;

        for(auto& pair:mpp)
            if(pair.second!=0)
                return false;

        return true;
    }
};

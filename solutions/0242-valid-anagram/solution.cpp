class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()) return false;

        unordered_map <char,int> charCount;

        for(char c:s){
            charCount[c-'a']++;
        }

        for(char c:t){
            charCount[c-'a']--;
        }

        for(auto &it: charCount){
            if(it.second!=0) return false;
        }

        return true;

    }
};

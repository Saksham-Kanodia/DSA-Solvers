class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        int freqS[26] ={0};
        int freqTarget[26] = {0};

        for(int i=0; i<s.length(); i++){
            freqS[s[i]-'a']++;
        }

        for(int i=0; i<target.length(); i++){
            freqTarget[target[i]-'a']++;
        }

        int ans = 1e9;

        for(int i=0; i<26; i++){
            if(freqTarget[i]>0){

                int copies = freqS[i]/freqTarget[i];

                ans = min(ans,copies);
            }
        }

        return ans;
    }
};

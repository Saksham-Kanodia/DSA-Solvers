class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alien_rank[26];

        for(int i=0; i<order.size(); i++){
            alien_rank[order[i]-'a']=i;
        }

        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int min_length = min(w1.size(), w2.size());
            bool mismatched = false;

            for(int k=0; k< min_length; k++){
                if(w1[k]!=w2[k]){
                    mismatched = true;

                    if(alien_rank[w1[k]-'a']>alien_rank[w2[k]-'a'])
                        return false;

                    break;
                }
            }

            if(!mismatched && w1.length()>w2.length()) return false;
        }

        return true;
    }
};

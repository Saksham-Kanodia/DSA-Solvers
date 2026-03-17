class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n= strs.size();

        //sort the array
        sort(strs.begin(),strs.end());

        //compare character by character the last and first word.
        int idx=0;
        for(int i=0; i<min(strs[0].length(),strs[n-1].length()); i++){
            if(strs[0][i]==strs[n-1][i])
                idx++;
            else 
                break;   
        }

        return strs[0].substr(0,idx);
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map <char,int> mpp;

        for(int i=0; i<n; i++){
            mpp[s[i]]+=1;
        }

        vector <pair<int,char>> vec;
        for(auto& it:mpp){
            vec.push_back({it.second,it.first});
        }

        sort(vec.rbegin(),vec.rend());

        string ans="";
        for(auto &pair:vec){
            ans+=string(pair.first,pair.second);
        }

        return ans;
    }
};

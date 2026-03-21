#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int beautySum(string s){
    int n=s.length();
    int beautySum=0;

    for(int i=0; i<n; i++){
        unordered_map <char,int> mpp;

        for(int j=i; j<n; j++){
            mpp[s[j]]++;

            int max_Freq=INT_MIN;
            int min_Freq=INT_MAX;

            for(auto& it:mpp){
                max_Freq=max(max_Freq, it.second);
                min_Freq=min(min_Freq, it.second);
            }

            beautySum+=(max_Freq-min_Freq);
        }
    }

    return beautySum;
}

int main(){
    string s ="aabcb";
    cout << beautySum(s) <<endl;

    return 0;
}
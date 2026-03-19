#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*Optimal Solution Logic:- To find the Longest Common Prefix in a string array, most optimal approach will be sorting.
Sort the entire array, and iterate over the first and last string character by characterand keep updating index variable. If mismatch found break,
and at last return substring of first(or last) uptil the index variable, which keeps track of last common prefix length.*/

//Time Complexity:- O(n*log n) to sort the array.
//space complexity:- O(1). no extra space used other than returning common prefix.
string LongestCommonPrefix(vector <string> str){
    int n = str.size();

    //sort the array.
    sort(str.begin(),str.end());

    //check for common prefix
    int idx=0;
    int k = min(str[0].length(),str[n-1].length());
    for(int i=0; i<k; i++){
        
        if(str[0][i]==str[n-1][i]){
            idx++;
        }
        else break;
    }
    
    return str[0].substr(0,idx);
}

int main(){
    
    vector <string> str = {"flower","flow","flight"};
    cout << "Longest Common Prefix: " << LongestCommonPrefix(str);
    return 0;
}
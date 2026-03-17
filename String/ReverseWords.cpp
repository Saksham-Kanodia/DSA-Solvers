#include <iostream>
#include <string>
using namespace std;

/*Logic:- To go about this problem, we carry out two steps:-

Step 1: Reverse the entire strings, so all words are reversed in position.
Step 2: Re-reverse the individual words to get the final output.*/

/*Time Complexity:- O(N) to reverse original string + O(N) to reverse individual words. Hence O(2N) so O(N).
Space Complexity:- O(1) as no extra space used.*/

void reverseRange(string &s, int i, int j){
    
    while(i<j){
        char temp = s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}

string reverseWords(string s){
    
    int n= s.length();
    int left =0;
    int right = n-1;

    while(left<right && s[left]==' ') left++;
    while(left<right && s[right]==' ') right--;

    //declare cleanStr and clean it up.
    string cleanStr = "";
    for(int i=left; i<=right; i++){
        if(s[i]!=' ')
            cleanStr+=s[i];
        else if(cleanStr.back()!=' ')
        cleanStr +=' ';
    }

    //now reverse cleanStr;
    int m=cleanStr.length();
    reverseRange(cleanStr,0,m-1);

    //reverse individual words now
    int start=0;
    for(int end=0; end<=m; end++){
        if(end==m||cleanStr[end]==' '){
            reverseRange(cleanStr,start, end-1);
            start=end+1;
        }
    }

    return cleanStr;
    
}

int main(){

    string s = "  the  sky  is blue  ";
    cout << reverseWords(s) <<endl;

    return 0;
}
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

    //reverse the entire sentence
    reverseRange(s,0,n-1);

    //re-reverse the individual words
    int start=0;
    for(int end=0; end<=n; end++){
        //if we hit a space or end of string, we've found a word boundary.
        if(end==n || s[end]==' '){
            reverseRange(s,start,end-1);
            start = end+1;//move start to beginning of next word.
        }
    }

    return s;
}

int main(){

    string s = "the sky is blue";
    cout << reverseWords(s) <<endl;

    return 0;
}
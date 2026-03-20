#include <iostream>
#include <string>
using namespace std;

/*Logic:- Generate all the possible rotations and compare with the target string. Put a for loop iteratiing over
string length, i.e. possible no. of rotations for a string, generate rotation by extracting last char of string, then 
deleting the last char and finally appending last char to the beginning of the string.*/

//Time Complexity:- O(n^2). To generate all the combinations.
//Space Complexity:- O(1). No extra Space used. 
bool areRotations(string s1, string s2){

    int n = s1.length();
    
    for(int i=0; i<n; i++){

        //check the rotations.
        if(s1==s2)
        return true;

        //form rotations
        char last = s1.back();
        s1.pop_back();
        s1=last+s1;
    }

    return false;
}

int main(){

    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1,s2) ? "true" : "false");
    return 0;
}
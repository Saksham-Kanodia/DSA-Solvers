#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*Brute Force Solution:- Put one nested loop, where outer loop iterates over both strings and mapping the characters at
same position to each other. Then inner loop iterates over entire sentence if any mismatch takes place, i.e. the mapping follows.*/

//Time Complexity:- O(n^2) To iterate over the sentences entirely.
//Space Complexity:- O(1). No extra space used.

bool checkIsomorphic(string s1, string s2){
    int n = s1.length();

    for(int i=0; i<n; i++){
        char c1 = s1[i];
        char c2 = s2[i];

        for(int j=0; j<n; j++){

            if(s1[j]==c1 && s2[j]!=c2)
            return false;

            if(s2[j]==c2 && s2[j]!=c1)
            return false;
        }
    }

    return true;
}

/*For the Optimal solution the approach we take is the Permanent Ids approach.
Assign IDs: As you iterate, if a character is new, assign it a permanent ID equal to its current index.
Compare IDs: For every position i, check the ID of s1[i] against the ID of s2[i].
Validate: If the IDs match, the characters are following the same "appearance pattern"; if they don't, the one-to-one mapping is broken.*/

//Time Complexity:- O(n). As we iterate once only through entire string.
/*Space Complexity:- O(1). Since the strings contain only lowercase English letters, 
the maximum size of each hash map is bounded by 26, making it constant space.*/
bool checkIsomorphic2(string s1, string s2){
    int n= s1.length();
    unordered_map <char,int> mpp1,mpp2;

    for(int i=0; i<n; i++){

        /*if character not seen before
        store its first occurence(permanent Id)*/
        if(mpp1.find(s1[i])==mpp1.end())
        mpp1[s1[i]]=i;

        /*if character not seen before store its first
        occurence(assign its permanent Id)*/
        if(mpp2.find(s2[i])==mpp2.end())
        mpp2[s2[i]]=i;

        //check if their first occurences(permanent IDs) match each other
        if(mpp1[s1[i]]!=mpp2[s2[i]])
        return false;

    }

    return true;

}

int main(){

    string s1 = "aab";
    string s2 = "xxy";

    if(checkIsomorphic(s1, s2)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }

    return 0;
    
}
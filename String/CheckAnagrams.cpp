#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*Brute Force Logic:- Check if the length of both strings is equal or not, if not, they are definitely not 
anagrams. Next, sort both the strings using sort function, now after sorting compare using sort function,
if the strings are now equal, the strings are anagrams, else they are not anagrams.*/

//Time Complexity:- O(nlogn + mlogm) to sort both the strings where n and m are no. of characters in both the strings respectively.
//Space Complexity:- O(1). No extra space used.
bool checkAnagrams(string s1, string s2){

    if(s1.length()!=s2.length())
    return false;

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    if(s1==s2);
    return true;
}

/*Optimal Solution Logic:- The most optimal solution of this problem will be to use a hashmap. We will iterate over the first
string and hash its characters(key--> character, value---> no. of occurences). nOw iterate over the second string and iterate over
the second string and using same hashmap hash this string just decrementing the count of each character this time. Aftewr second string
is also hashed, we can now iterate over the hashmap and if there exists any pair whose count of occurences is not zero after
incrementing and decrementing, then the strings are not anagram.(as the count of occurences of each characters in both the strings is not exactly same).*/

// Time Complexity:- O(n+m). To iterate over both strings.
// Space Complexity:- O(1) space as there are at max 26 character possible(lower English alphabets). Therefore, constant space.

bool checkAnagrams2(string s1, string s2){

    if(s1.length()!=s2.length())
    return false;

    unordered_map <char,int> charCount;

    for(char ch:s1)
    charCount[ch]+=1;
    
    for(char ch:s2)
    charCount[ch]-=1;
    
    for(auto& pair:charCount){
        if(pair.second!=0)
        return false;
    }

    return true;
}

int main(){
    string s1 = "geeks";
    string s2 = "ksege";

    cout <<(checkAnagrams(s1,s2)? "True":"False")<<endl;//calling brute force solution
    cout <<(checkAnagrams2(s1,s2)? "True":"False");//calling most optimal solution

    return 0;
}
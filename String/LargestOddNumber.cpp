#include <iostream>
#include <string>
using namespace std;

/*Brute Force Solution:- Iteerate through all possible substrings in the string, now check if, given one ends with odd number
if yes, assign it as current and compare with max_odd substring. if the length of current is more than max_odd then obviously current
is larger, else if their lengths are equal compare lexicographically and update accordingly. Returning the final updated max_odd.*/

//Time Complexity:- O(n^3) n square to generate all substrings and n to compare two substrings.
//Space Complexity:- O(n) to store largest substring found.

string largestOddNumber(string s){
    string max_odd = "";
    int n= s.length();

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            if((s[j]-'0')%2!=0){

                string current = s.substr(i,j-i+1);

                if(current.length()>max_odd.length())
                max_odd=current;

                else if(current.length()==max_odd.length())
                if(current>max_odd) max_odd=current;
            }
        }
    }

    return max_odd;
}

/*Optimal Solution Logic:- Use 2 pointers to iterate over the string.
fix the start poiner at beginning and move end ointer, if we find a odd number
from the end, that string will be largest.*/

//Time Complexity:- O(n) to iterate over string worst case scenario.
//Space complexity:- O(n) , to return the answer string.

string largestOddNumber2(string s){
    //apply 2 pointers
    int n=s.length();
    int start=0,end=n-1;

    while(start<=end){
        if((s[end]-'0')%2!=0)
        return s.substr(start,end+1);
        else end--;
    }

    return "";
}

int main(){

    string S = "12345";
    cout << largestOddNumber(S)<<endl;//calling brute force
    cout << largestOddNumber2(S)<<endl;//calling optimal solution.

    return 0;
}
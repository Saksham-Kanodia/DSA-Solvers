#include <iostream>
#include <string>
using namespace std;

/*Brute Force Logic:- Generate all substrings just like you generate subarrays, for each substring put a chaeckPalindrome function,
explicitly track the maximum length of the Palindromic Substring. Finally return the substring with maximum Length.*/

//Time Complexity:- O(n^3). 
//Space Complexity:- O(1).
bool checkPalindrome(string s, int low, int high){
    while(low<high){
        if(s[low]!=s[high])
        return false;

        low++;
        high--;
    }
    return true;
}

string longestPalindromicSubstring(string s){
    int n= s.length();
    int maxLen =1,start=0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(checkPalindrome(s,i,j) && (j-i+1)>maxLen){
                maxLen=j-i+1;
                start =i;
            }
        }
    }

    return s.substr(start,maxLen);

}

/*Optimal Solution:- Expansion From Centre. Go to each character, set low at that character and high, same as low if
odd length, or one ahead of low if even length. Now since centre has been set, start expanding, and continue uptil either the
pointers reach boundary or palindromic pattern is broken,i.e. s[low]!=s[high]. Keep traack of start of seq as low, and maxLen. 
Then finally return s.substr(start,maxLen).*/

//Time Complexity:- O(n^2).
//Space Complexity:- O(1).
string longestPalSubstr(string s){

    int n= s.length();
    int start =0,maxLen=1;

    for(int i=0; i<n; i++){

        //if j==0, means odd. and if j==1, means even.
        for(int j=0; j<=1; j++){
            int low =i; 
            int high = i+j;

            while(low>=0 && high<n && s[low]==s[high]){
                int currLen=high-low+1;

                if(currLen>maxLen){
                    start=low;
                    maxLen=currLen;
                }

                low--;
                high++;
            }
        }
    }
    
    return s.substr(start,maxLen);

}

int main(){

    string s ="for geeksskeegfor";
    cout << longestPalSubstr(s) << endl;

    return 0; 
}
#include <iostream>
#include <string>
using namespace std;


/*Logic:- Using two Pointers, compare characters from both inwards,
if any pair mismatches, it's not a palindrome.*/

/*Time Complexity:- O(N). Each character is visited at once as we move inwards.*/
/*Space Complexity:- O(1). No extra space used.*/

bool isPalindrome(string S){
    //2 pointers on string.
    int left=0;
    int right = S.length()-1;

    while(left<right){

        //string is not palindrome.
        if(S[left]!=S[right])
        return 0;

        left++;
        right--;
    }

    //string is palindrome.
    return 1;
}

int main(){

    string s= "abba";
    cout << isPalindrome(s) <<endl;

    return 0;
}
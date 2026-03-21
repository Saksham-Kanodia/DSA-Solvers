#include <iostream>
#include <string>
using namespace std;

/*Logic:-
1.)Skip the leading whitespaces by iterating from the first character.
2.) Now, check for at most one sign character ('+' or '-') and maintain a sign variable to keep track of the sign of the number.
3.) Finally, read all the digits and construct the number until the first non-digit character is encountered or end of the input string is reached. 
4.) While constructing the number, if the number becomes greater than 2^31 - 1, print 2^31 - 1. Similarly, if the number becomes less than -231, print -231.*/

//Time Complexity:- O(n).
//Space Complexity :- O(1).
int stringToInt(string s){
    int sign =1,res=0,idx=0;

    while(s[idx]==' ') idx++;

    if(s[idx]=='+'||s[idx]=='-'){
        if(s[idx++]=='-')
        sign=-1;
    }

    while(s[idx]>='0' && s[idx]<='9'){

        if(res>INT_MAX/10||res==(INT_MAX/10) && s[idx]-'0'>7)
        return sign == 1 ? INT_MAX:INT_MIN;

        res = 10*res + (s[idx]-'0');

    }

    return res*sign;
}

int main(){

    string s = "    -00000123";
    cout << stringToInt(s)<< endl;

    return 0;
}
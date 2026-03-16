#include <iostream>
#include <string.h>
using namespace std;

string removeOuterParentheses(string S){
    string result = "";
    int count =0;

    for(char c:S){
        if(c=='('){
            if(count>0) result+=c;
            count++;
        }
        else{
            if(count>1) result+=c;
            count--;
        }
    }

    return result;
}


int main(){

    string S = "(()())(())()";

    cout << removeOuterParentheses(S);

    return 0;
}
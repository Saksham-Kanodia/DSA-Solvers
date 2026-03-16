#include <iostream>
#include <string>
using namespace std;


/*Logic:- If you are standing on ground (Depth 0), the first step we take is UP in the
building- don't count the door( '(' ). While you are inside (Depth 1 or higher), record everything.
When you take the last step back to the ground, don't count the exit( ')' ).*/

/*Time Complexity:- O(N). As we are travesing entire strings, so O(N) where N is no. of elements of string.*/
/*Space Complexity:- O(N). Only to return the answer.*/

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
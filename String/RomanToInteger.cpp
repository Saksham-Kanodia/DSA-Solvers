#include <iostream>
#include <string>
using namespace std;

int valueChar(char ch){
    if(ch=='I')
    return 1;
    if(ch=='V')
    return 5;
    if(ch=='X')
    return 10;
    if(ch=='L')
    return 50;
    if(ch=='D')
    return 500;
    if(ch=='C')
    return 100;
    if(ch=='M')
    return 1000;
    return -1;
}

//Time Complexity:- O(n). We traverse the string for every character.
//Space Complexity:- O(1). Constant extra space used.
int romanToDecimal(string s){
    int res=0;

    for(int i=0; i<s.length(); i++){
        int s1 = valueChar(s[i]);

        if(i+1<s.length()){
            int s2=valueChar(s[i+1]);

            if(s1>=s2)
            res+=s1;

            else{
                res+=(s2-s1);
                i++;
            }
        }

        else{
            res+=s1;
        }
    }

    return res;

}

int main(){

    string s = "IX";
    cout << romanToDecimal(s) << endl;
    return 0;
}
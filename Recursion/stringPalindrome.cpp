# include <bits/stdc++.h>
using namespace std;

void f(string str,string org,int l, int n){
    if(l>=n/2){
        if(str==org) cout << "String is Palindrome";
        else cout << "String is not Palindrome";
        return;
    }

    char ch1 = str[l];
    str[l]= str[n-1-l];
    str[n-1-l]= ch1;

    f(str, org, l+1, n);
}

int main(){

    cout << "Enter a string: ";
    string str;
    cin >> str;

    string org = str;

    //check if string is palindrome
    f(str,org,0,str.length());
    return 0;
}
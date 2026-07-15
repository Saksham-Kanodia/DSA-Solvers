# include <bits/stdc++.h>
using namespace std;

int factorialOfN(int n){
    if(n==1) return 1;

    return n*factorialOfN(n-1);
}

void factorialOfN(int i, int fact){
    if(i<1){
        cout << fact << " ";
        return;
    }

    factorialOfN(i-1, fact*i);
}

int main(){

    int n;
    cin >> n;

    factorialOfN(n,1);
    cout << factorialOfN(n) << " ";

    return 0;
}
# include <bits/stdc++.h>
using namespace std;

int sumOfNumbers(int n){
    if(n==0) return 0;

    return n+ sumOfNumbers(n-1);
}

void sumOfNumbers(int i, int sum){
    if(i<1){
        cout << sum << " ";
        return;
    }
    sumOfNumbers(i-1, sum+i);
}

int main(){
    int n;
    cin >> n;

    sumOfNumbers(n, 0);
    cout << sumOfNumbers(n) << " ";

    return 0;
}
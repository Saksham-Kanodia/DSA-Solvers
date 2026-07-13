#include <bits/stdc++.h>
using namespace std;\

void recPrint(int i, int n){
    if(i>n) return;

    cout << "Saksham" << endl;
    recPrint(i+1, n);
}

int main(){

    int n;
    cin>>n;
    
    recPrint(1,n);

    return 0;

}
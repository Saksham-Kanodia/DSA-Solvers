#include <bits/stdc++.h>
using namespace std;

int isDigit(char ch){
    return ch - '0';
}

int rotations(char ch1, char ch2){
    int a = isDigit(ch1);
    int b = isDigit(ch2);

    int diff  = abs(a-b);

    return min(diff, 10-diff);
}

void reverse(string &s, int k){
    int i=k;
    int j=s.length()-1;

    while(i<j){
        char temp = s[i];
        s[i]=s[j];
        s[j]=temp;

        i++;
        j--;
    }
}

//Brute Force Approach - T.C. O(n^2*k) S.C. O(1).
int minRotations1(int n, string s){

    int minCount =0;

    for(int k=0; k<n; k++){

        reverse(s,k);
        int count = rotations('0',s[0]);

        for(int i=0; i<s.length()-1; i++){
            count+=rotations(s[i],s[i+1]);
        }

        if(count<minCount || k==0){
            minCount =count;
        }
    }

    return minCount;
}

//Optimal Solution - T.C. O(n) S.C. O(1).
int minRotations2(int n, string s) {

        int minCost =0;

        int originalCost = rotations('0',s[0]);
        for(int i=0; i<n-1; i++){
            originalCost+=rotations(s[i],s[i+1]);
        }

        for(int k=0; k<n; k++){
            if(k==0){
                int cost = originalCost - rotations('0', s[0]) + rotations('0',s[n-1]);
                minCost = cost;
            }
            else{
                int cost = originalCost - rotations(s[k-1],s[k]) + rotations(s[k-1],s[n-1]);
                if(cost<minCost) minCost = cost;
            }
        }

        return minCost;
    }

int main(){

    string s = "1502";

    int n = s.length();   

    cout<<minRotations1(n,s)<<endl;
    cout<<minRotations2(n,s)<<endl;
}
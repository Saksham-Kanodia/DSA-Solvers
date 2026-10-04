class Solution {
public:

int isDigit(char ch){
    return ch -'0';
}

int rotations(char c1 , char c2){

    int a = isDigit(c1);
    int b = isDigit(c2);

    int diff = abs(a-b);

    return min(diff, 10-diff);

}

void reverse(int k, string &s){

    int i=k;
    int j= s.length()-1;

    while(i<j){

        char temp = s[i];
        s[i]=s[j];
        s[j] = temp;

        i++; j--;
    }
}
    int minRotations(int n, string s) {

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
};

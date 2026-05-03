class Solution {
public:
 
int factorSum(int n){
    int total = 0;

    for(int i=2; (i*i)<=n; i++){
        while(n%i==0){
            total+=i;
            n/=i;
        }
    }
    if(n>1) total+=n;

    return total;
}

    int smallestValue(int n) {
        while(true){
            int s = factorSum(n);

            if(s==n)
            return n;

            n=s;
        }
    }
};

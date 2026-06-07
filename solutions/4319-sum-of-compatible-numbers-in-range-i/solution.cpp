class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum =0;

        if((n-k)<0){
          for(int x = 1; x<=(n+k); x++){
            if((n&x)==0) 
                sum+=x;
        }  
        }
        else{
            for(int x = n-k; x<=(n+k); x++){
            if((n&x)==0) 
                sum+=x;
        }  
        }

        return sum;
    }
};

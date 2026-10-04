class Solution {
public:

    int isDigit(char ch){

        if(ch=='0') return 0;
        if(ch=='1') return 1;
        if(ch=='2') return 2;
        if(ch=='3') return 3;
        if(ch=='4') return 4;
        if(ch=='5') return 5;
        if(ch=='6') return 6;
        if(ch=='7') return 7;
        if(ch=='8') return 8;
        if(ch=='9') return 9;

        return 0;
    }

    int rotations(char ch1, char ch2){
        int a = isDigit(ch1);
        int b= isDigit(ch2);

        int diff = abs(a-b);

        return min(diff,10-diff);
    }
    
    int minRotations(string s) {
        int count =rotations('0',s[0]);
        int n= s.length();

        for(int i=0; i<n-1; i++){
            count+= rotations(s[i],s[i+1]);
        }

        return count;
    }
};

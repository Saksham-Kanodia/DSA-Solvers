class Solution {
public:
    string largestOddNumber(string num) {
        //make use of 2 pointers
        int n=num.length();
        int start=0,end=n-1;

        //fix start at beginning and iterate over the string.
        while(end>=start){
            if((num[end]-'0')%2!=0)
            return num.substr(start,end+1);
            else end--;
        }

        //if no such odd number exists return an empty string.
        return "";
    }
};

class Solution {
public:
    void reverseRange(string &s, int i, int j){
        while(i<j){
            char temp = s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int n = s.length();

        //let us clean the string to counter leading and trailing spaces.
        string cleanStr = "";
        int left =0, right=n-1;//2 pointers.
        while(left<=right && s[left]==' ') left++;
        while(left<=right && s[right]==' ') right--;

        //counter any double spaces in between
        for(int i=left; i<=right; i++){
            if(s[i] != ' '){
                cleanStr += s[i];
            }
            else if(cleanStr.back()!=' '){
                cleanStr+=' ';//only add a space if previous char wasn't one.
            }
        }
        
        //reverse the entire string.
        int m=cleanStr.length();
        reverseRange(cleanStr,0,m-1);

        //re-reverse the individual words.
        int start=0;
        for(int end=0; end<=m; end++){
            if(end==m || cleanStr[end]==' '){
                reverseRange(cleanStr,start,end-1);
                start=end+1;
            }
        }

        return cleanStr;
    }
};

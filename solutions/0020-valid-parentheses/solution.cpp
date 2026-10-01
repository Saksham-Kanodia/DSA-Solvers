class Solution {
public:

bool checkMatchingPair(char ch1,char ch2){

    return ((ch1=='(' && ch2==')') || 
            (ch1=='[' && ch2==']') ||
            (ch1=='{' && ch2=='}'));
}
    bool isValid(string s) {
        stack <char> st;
        
        for(int i=0; s[i]!='\0'; i++){

            char ch = s[i];

            if(ch=='('|| ch == '[' || ch== '{'){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }

                if(!checkMatchingPair(st.top(),ch))
                        return false;

                else
                st.pop();
            }
        }

        if(!st.empty())
        return false;

        return true;
    }
};

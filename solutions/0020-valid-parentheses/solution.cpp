class Solution {
public:

bool isMatchingParentheses(char ch1, char ch2){

    return (ch1== '(' && ch2== ')'
            || ch1=='[' && ch2 == ']'
            || ch1 == '{' && ch2 == '}');

}
    bool isValid(string s) {

        stack <char> st;
        
        for(char c:s){
            if(c=='(' || c== '[' || c=='{')
                  st.push(c);

            else{
                if(!st.empty() && isMatchingParentheses(st.top(),c))
                st.pop();

                else
                return false;
            }
        }

        return st.empty();
    }
};

class Solution {
public:

bool isOperator(string ch){
    return (ch == "+"|| ch == "-"|| ch == "*"|| ch == "/");
}
    int evalRPN(vector<string>& tokens) {
        stack <int> st;

        for(string s:tokens){

            if(!isOperator(s)){
                st.push(stoi(s));
            }

            else{

            char ch = s[0];
                    
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if(ch == '+'){
                st.push(a+b);
            }

            else if(ch == '-'){
                st.push(a-b);
            }

            else if(ch == '*'){
                st.push(a*b);
            }

            else if(ch== '/'){

                if(b!=0)
                st.push(a/b);

            }

            }
        }

        return st.top();

    }
};

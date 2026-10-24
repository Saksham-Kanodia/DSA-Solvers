class Solution {
public:

    int calPoints(vector<string>& operations) {

        stack <int> st;

        for(string s:operations){
            
            if(s=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b);
                st.push(a);
                st.push(a+b);
            }

            else if(s=="D"){
                int a = st.top();
                st.push(2*a);
            }

            else if(s=="C"){

                st.pop();
            }

            else{
                st.push(stoi(s));
            }

        }

        int finalAns =0;

        while(!st.empty()){
            finalAns+=st.top();
            st.pop();
        }

        return finalAns;
        
    }
};

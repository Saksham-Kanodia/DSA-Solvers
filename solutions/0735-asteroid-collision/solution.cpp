class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack <int> st;

        for(int asteroid: asteroids){

            bool destroyed = false;

            while(!st.empty() && asteroid<0 && st.top()>0){

                if(abs(asteroid) > st.top())
                st.pop();

                else if(abs(asteroid) == st.top()){
                    st.pop();
                    destroyed=true;
                    break;
                }

                else{
                    destroyed = true;
                    break;
                }

            }

            if(!destroyed)
            st.push(asteroid);

        }

        vector <int> res;

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n= s.length();

        for(int i=0; i<n; i++){
            if(s==goal)
            return true;

            char last = s.back();
            s.pop_back();
            s=last+s;
        }

        return false;
    }
};

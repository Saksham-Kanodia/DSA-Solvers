class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int max_depth=0, current_max=0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                current_max++;
                max_depth=max(max_depth,current_max);
            }
            else if(s[i]==')'){
                if(current_max==0)
                return -1;

                else 
                current_max--;
            }
        }

        if(current_max!=0)
        return -1;

        else
        return max_depth;
    }
};

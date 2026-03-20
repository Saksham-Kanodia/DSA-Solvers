#include <iostream>
#include <string>
using namespace std;

/*Most Optimal Solutoion Logic:- Take two variable current_max and max_depth and initialize both as 0, then iterate
over the string, if the current character is "(", simply increment current_max and updte max_depth if required. Then if 
current character is ")" check if current_max is greater than 0, if yes decrement current_,max, and if not return -1, cause
string is unbalanced in that case. Then at the end check if(current_max==0) cause if it is not zero, string is unbalanced
and if yes, then simply return max_depth.*/

//Time Complexity:- O(n). One iteration over the array.
//Space Complexity:- O(1). No extra space used.
int maxDepth(string s){
    int n=s.length();
    int max_depth=0, current_max=0;

    for(int i=0; i<n; i++){
        if(s[i]=='('){
        current_max+=1;
        max_depth=max(current_max,max_depth);
        }

        if(s[i]==')'&&current_max>0)
        current_max-=1;
        else if(s[i]==')'&&current_max==0)
        return -1;
    }

    if(current_max==0)
    return max_depth;
    else
    return -1;
    
}

int main(){

    string s = "( ((X)) (((Y))) )"; 
    cout << maxDepth(s); 
    return 0; 
}
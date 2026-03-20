#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*Logic:- For sorting characters by freq, we can declare first a vector of pairs (int,char) where, first value
denotes frequency of character and second value denotes the character. Then iterate over entire string, store
frequency of each character int the string, using a countFreq function(which iterates over string to count frequency)
and add it to the pair vector, Next we can sort the vector by using built in sort function(sorting the array by first value ,i.e. frequency),
can just iterate over the pair, and in an answer string form the answer by using second value of pairs of our vector. */

// Time Complexity:- O(n^2). To count freq for each character
// Space Complexity:- O(1). As 26 letters, lowercase English alphabets, it is constant space only in practice.

int countFreq(string s, char ch){
    int n = s.length();
    int count=0;

    for(int i=0; i<n; i++){
        if(s[i]==ch)
        count++;
    }

    return count;
}

string sortByFreq(string s){
    int n=s.length();

    vector <pair<int,char>> vp;

    for(int i=0; i<n;i++){
        vp.push_back(make_pair(countFreq(s,s[i]),s[i]));
    }

    //sort by frequency(i.e. pair's first value)
    sort(vp.begin(),vp.end());

    string ans ="";
    for(auto& pair:vp){
        ans+=pair.second;
    }

    return ans;
    
}

/*Optimal Solution:- Using hashmap and Custom Sorting. This a hashing approach where we
create first a hashmap and store the value of each char of string against its frequency. Then we will append
hashmap values, to the pair vector and then sort this vector and then create our answer string(by using string(count,char)) 
otherwise pair.second will only append once and we want it freq times.*/

//Time Complexity:- O(n). To count frequency. Sort of at max 26 alphabets in constant time only
//Space Complexity:- O(1). As only 26 lowercase english alphabets so constant space only.

string sortByFreq2(string s){

    int n=s.length();

    unordered_map <char,int> mpp;
    for(int i=0; i<n; i++){
        mpp[s[i]]+=1;
    }

    vector <pair<int,char>> vp;
    for(auto& it:mpp){
        vp.push_back({it.second,it.first});
    }

    sort(vp.begin(),vp.end());

    string ans ="";
    for(auto& pair:vp){
        ans+=string(pair.first,pair.second);
    }

    return ans;

}

int main(){

    string s = "geeksforgeeks";
    cout << sortByFreq2(s);
    return 0;
}
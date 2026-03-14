# include <bits/stdc++.h>
using namespace std;

/*As the problem says we need to maximize the minimium no. of possible farms. This statement alone tells us it is a classical Binary Search on Answers problem.
Problem Explanation: We have been given an array dentoing (N farms), and we have to select out the minimum harvest amount obeying the mentioned constraints such
that exactly K farms are selected. And further we have to maximize this minimum amount.*/


//Time Complexity:- O(N*log(max_Element)).
//Space Complexity:- O(1).
bool check(int N, int K, int F, vector <int> &harvest, int min_Harvest){

    //Farm 0 must be included
    if(harvest[0]<=min_Harvest) return false;

    int countOfFarms=1;//Farm 0 has been included.
    int currentPos=0;

    for(int i=1; i<N; i++){

        //if a farm is reachable and meets harvest Threshold.
        if(i-currentPos<=F+1 && harvest[i]>=min_Harvest){
            countOfFarms++;//include the farm we are at.
            currentPos=i;//move to this farm.
        }

        if (countOfFarms>=K) return true;
    }

    return countOfFarms>=K;
}

//binary search to maximize the minimum value.
int harvestFestival(int N, int K, int F, vector <int> &harvest){
    int low =0;
    int high = *max_element(harvest.begin(),harvest.end());
    int max_Value = low;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(check(N,K,F,harvest,mid)){
            max_Value = mid;
            low=mid+1;
        }
        else
        high = mid-1;
    }

    return max_Value;
}

int main(){
    int N=5;
    int K=3;
    int F=1;

    vector <int> harvest = {20,5,15,2,30};
     
    cout << "Max Harvest Value: " << harvestFestival(N,K,F,harvest);
}
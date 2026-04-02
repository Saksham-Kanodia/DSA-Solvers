#include <iostream>
#include <vector>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){

    vector <int> arr = {2,54,7,9};
    Node* head = new Node(arr[0]);

    cout << head->data;

    return 0;
}
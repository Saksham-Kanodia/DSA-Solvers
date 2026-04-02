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
        next= nullptr;
    }

};

Node* convertArr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

bool searchIfPresent(Node* head, int target){
    Node* temp = head;

    while(temp!=nullptr){
        if((temp->data)==target)
        return true;
        temp=temp->next;
    }

    return false;
}

int main(){

    vector <int> arr = {3,1,2,4,5};
    Node* head = convertArr2LL(arr);

    cout << searchIfPresent(head,6);

    return 0;
}
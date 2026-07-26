#include <iostream>
#include <vector>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover = temp;
    }

    return head;
}

Node* deleteHeadOfLL(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head= head-> next;
    delete temp;
    return head;
}

Node* deleteTailOfLL(Node* head){
    if(head == nullptr || head-> next == nullptr){
        delete head;
        return NULL;
    }

    Node* temp = head;
    while(temp-> next -> next !=nullptr)
    temp = temp->next;

    delete temp->next;
    temp->next=nullptr;

    return head;

}

Node* deleteKthElementOfLL(Node* head, int k){

    if(head==NULL) return NULL;

    if(k==1){
        Node* temp = head;
        head = head-> next;
        delete temp;
        return head;
    }


    Node* temp = head;
    int cnt =1;
    Node* prev;

    while(cnt!=k){
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

int main(){
    vector <int> arr = {3,1,5,6,7};
    Node* mover = deleteKthElementOfLL(convertArr2LL(arr),3);

    while(mover!=nullptr){
        cout << mover->data << " ";
        mover = mover->next;
    }

    return 0;
}
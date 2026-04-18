# include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1 ,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* convertToDll(vector <int> arr){
    Node * head = new Node(arr[0]);
    Node * prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;

}

void print(Node* head){
    while(head!=NULL){
        cout << head-> data << " ";
        head = head-> next;
    }
}

Node* deleteHeadOfDll(Node* head){
    if(head == nullptr|| head->next == nullptr){
        return NULL;
    }

    Node* prev = head;
    head = head -> next;

    head -> back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
    
}

Node* deleteTailOfDLL(Node* head){
    if(head == NULL|| head-> next == NULL){
        return NULL;
    }

    Node* mover = head;

    while(mover->next->next!=NULL){
        mover =mover->next;
    }

    Node* tail = mover->next;
    mover -> next = nullptr;
    tail-> back = nullptr;

    delete tail;
    return head;

}

Node* deleteKthElementOfDLL(Node* head, int k){
    int cnt =0;
    Node* temp = head;
     
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp -> next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }

    else if(prev == NULL){
        return deleteHeadOfDll(head);
    }

    else if(front ==NULL){
        return deleteTailOfDLL(head);
    }

    else{
        prev-> next = front;
        front -> back = prev;

        temp->next = nullptr;
        temp->back = nullptr;

        delete temp;
        return  head;
    }

    return head;
}

void deleteNode(Node* node){
    Node* prev = node -> back;
    Node* front = node -> next;

    if(front == NULL){
        prev -> next = NULL;
        node-> back = NULL;

        delete node;
    }

    prev-> next = front;
    front-> back = prev;

    node-> next = nullptr;
    node-> back = nullptr;

    delete node;
}



int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertToDll(arr);
    deleteNode(head->next->next);


    print(head);
    return 0;
}
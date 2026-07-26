# include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
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

Node* convertArrToDLL(vector <int> arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next =temp;
        prev =temp;
    }

    return head;
}

void print(Node* head){

    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp-> next;
    }
}

Node* insertionBeforeHeadOfDLL(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head -> back  = newHead;

    return newHead;
}

Node* insertionBeforeTailOfDLL(Node* head, int val){
    Node* tail= head;

    while(tail-> next != NULL){
        tail = tail -> next;
    }

    Node* temp = new Node(val);
    Node* prev = tail -> back;

    prev-> next = temp;
    tail-> back = temp;

    temp-> next = tail;
    temp-> back = prev;

    return head; 
}

Node* insertBeforeKthElementOfDLL(Node* head, int k,int val){
    int cnt =0;
    Node* temp = head;

    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;

        temp = temp->next;
    }

    Node* prev = temp-> back;
    Node* newNode = new Node(val);

    if(prev == NULL){
        return insertionBeforeHeadOfDLL(head, val);
    }

    prev-> next = newNode;
    temp -> back = newNode;

    newNode -> next = temp;
    newNode -> back = prev;

    return head;
}

void insertionBeforeNode(Node* node, int val){
    Node* prev = node-> back;
    Node* newNode = new Node(val,node, prev);

    prev-> next = newNode;
    node-> back = newNode;
}

int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArrToDLL(arr);
    insertionBeforeNode(head->next->next, 10);

    print(head);
    return 0;
}
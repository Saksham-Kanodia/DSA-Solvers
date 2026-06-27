/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

ListNode* reverseLL(ListNode* temp){
    ListNode* t = temp;
    ListNode* prev = NULL;

    while(t!=NULL){
        ListNode* front = t-> next;
        t->next = prev;
        prev = t;
        t= front;
    }
    return prev;
}

ListNode* findKthNode(ListNode* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k-=1;
        temp= temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* nextNode; ListNode* prevNode= NULL;

        while(temp!=NULL){
            ListNode* KthNode = findKthNode(temp,k);

            if(KthNode==NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }

            nextNode = KthNode-> next;
            KthNode->next = NULL;
            KthNode = reverseLL(temp);

            if(temp==head) head = KthNode;
            else prevNode->next =KthNode;

            prevNode = temp;
            temp = nextNode;
        }
        return head;      
    }
};

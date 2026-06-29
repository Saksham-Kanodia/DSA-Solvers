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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head-> next == NULL) return head;

        ListNode* tail = head;
        int length =0;

        length +=1;
        while(tail -> next !=NULL){
            length ++;
            tail = tail -> next;
        }

        k = (k % length);
        if(k==0) return head;

        tail-> next = head;

        ListNode* temp = head;
        int res = length -k;

        res-=1;
        while(res>0 && temp!=NULL){
            res-=1;
            temp = temp -> next;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

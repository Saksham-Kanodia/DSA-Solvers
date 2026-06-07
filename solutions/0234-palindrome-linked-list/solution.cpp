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

ListNode* reverseLinkedList(ListNode* node){
    ListNode* newHead;
    ListNode* back = NULL;
    ListNode* temp = node;

    while(temp!=NULL){
        ListNode* front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }

    newHead = back;

    return newHead;

}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reverseLinkedList(slow -> next);

        ListNode* first = head;
        ListNode* second  = newHead;

        while(second!=NULL){
            if(first->val != second->val){
                newHead = reverseLinkedList(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }

        newHead = reverseLinkedList(newHead);
        return true;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* mover = node;

        while(mover->next->next!=nullptr){
            mover->val = (mover->next)-> val;
            mover=mover->next;
        }

        mover->val = (mover->next)->val;
        delete(mover->next);
        mover->next=nullptr;


    }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp=head;
        int k=0;

        while(temp!=NULL){
            k++;
            if(k==left) break;
            temp=temp->next;
        }

        ListNode* leftNode = temp;
        stack <int> st;

        while(temp!=NULL){
            st.push(temp->val);
            if(k==right) break;
            temp = temp -> next;
            k++;
        }

        temp = leftNode;
        k=left;

        while(temp!=NULL){
            temp->val = st.top();
            st.pop();
            if(k==right) break;
            temp = temp -> next;
            k++;
        }

        return head;
    }
};

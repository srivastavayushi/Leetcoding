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
    void reversee(ListNode* &head,ListNode* dummy){
        if(dummy->next == NULL){
            head = dummy;
            return;
        }
        reversee(head,dummy->next);
        ListNode* temp = dummy->next;
        temp->next = dummy;
        dummy->next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        reversee(head,head);
        return head;
    }
};
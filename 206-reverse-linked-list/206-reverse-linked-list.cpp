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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_ptr = head->next;
        
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = next_ptr;
            if(next_ptr != NULL) next_ptr = next_ptr->next;
            
        }
        
        return prev;
    }
};
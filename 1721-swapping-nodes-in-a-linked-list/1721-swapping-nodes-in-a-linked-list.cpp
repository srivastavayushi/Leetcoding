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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i=1;i<=k;++i){
            slow=slow->next;
        }
        ListNode* temp = slow;
        
        while(temp!=NULL){
            fast = fast->next;
            temp=temp->next;
        }
        swap(slow->val,fast->val);
        return start->next;
    }
};
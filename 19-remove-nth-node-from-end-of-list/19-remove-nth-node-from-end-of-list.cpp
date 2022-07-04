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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i=1;i<=n;++i){
            slow=slow->next;
        }
        
        while(slow->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = fast->next->next;
        return start->next;
    }
};
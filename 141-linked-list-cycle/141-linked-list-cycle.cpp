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
    bool hasCycle(ListNode *head) {
        if(!head || head->next == NULL) return false;
        
        map<ListNode*, bool>mpp;
        
        ListNode* temp = head;
        
        while(temp){
            if(mpp.find(temp) != mpp.end()) return true;
            mpp[temp] = true;
            temp = temp->next;
        }
        
        return false;
    }
};
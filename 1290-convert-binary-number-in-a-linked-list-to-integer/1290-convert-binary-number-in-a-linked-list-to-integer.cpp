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
        
    int getLength(ListNode* head){
        int k = 0;
        ListNode* temp = head;
        while(temp != NULL){
            k++;
            temp = temp-> next;
        }
        return k;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int index = getLength(head)-1;
        int res = 0;
        
        
        while(temp != NULL){
            int num = temp-> val;
            num = num * pow(2, index);
            res += num;
            index--;
            temp = temp-> next;
        }
        
        return res;
    }
    
};

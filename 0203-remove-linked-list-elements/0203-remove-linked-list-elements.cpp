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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            temp ->next = NULL;
            delete temp;
        }    
        if(!head) return NULL;
        ListNode* prev = head;
        while(prev->next != NULL)
        {
            // if(prev->next == NULL) return head;
            if(prev->next->val == val)
            {
                ListNode* temp = prev->next;
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else prev = prev->next;
        }
        return head;
        
    }
};
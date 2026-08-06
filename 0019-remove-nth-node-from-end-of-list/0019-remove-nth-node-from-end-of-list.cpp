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
        if(!head->next && n == 1) return NULL;
        int count = 0;
        ListNode* temp = head;
        while(temp)temp = temp->next,count++;
        int front = count - n +1;
        if(front == 1)
            return head->next;
        temp = head;
        for(int i = 1; i < front - 1; i++)temp = temp->next;
        temp->next = temp->next->next;
        return head;

    }
};
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
private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while(cur != NULL)
        {
            next  = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* r1 =  reverseList(l1);
       ListNode* r2 =  reverseList(l2);
        ListNode* temp=NULL;
        int sum = 0, c = 0;
        while(r1 && r2)
        {
            sum = r1->val + r2->val+c;
            if(sum >= 10) sum = sum%10,c = 1;
            else c = 0;
            ListNode* newNode = new ListNode(sum);
            newNode->next = temp;
            temp = newNode;
            r1 = r1->next;
            r2 = r2->next;
        }
        while(r1)
        {
            sum = r1->val + c;
            if(sum >= 10) sum %= 10,c = 1;
            else c = 0;
            ListNode* newNode = new ListNode(sum);
            newNode->next = temp;
            temp = newNode;
            r1 = r1->next;
        }
        while(r2)
        {
            sum =r2->val+c;
            if(sum >= 10) sum %= 10,c = 1;
            else c = 0;
            ListNode* newNode = new ListNode(sum);
            newNode->next = temp;
            temp = newNode;
            r2 = r2->next;
        }
        if(c)
        {
            ListNode* newNode = new ListNode(c);
            newNode->next = temp;
            temp = newNode;
        }
        return temp;
    }
};
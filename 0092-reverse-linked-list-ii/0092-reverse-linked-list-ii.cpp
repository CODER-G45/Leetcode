class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* last = &dummy;
        for (int i = 0; i < left - 1; i++) prev = prev->next;
        for (int i = 0; i < right - 1; i++) last = last->next;
        ListNode* f = prev->next;
        ListNode* e = last->next;
        ListNode* after = e->next;
        ListNode* t1 = f->next;
        ListNode* t2 = t1 ? t1->next : nullptr;
        ListNode* x = f;
        while (x != e) {
            t1->next = x;
            x = t1;
            t1 = t2;
            t2 = t2 ? t2->next : nullptr;
        }
        prev->next = e;
        f->next = after;
        return dummy.next;
    }
};
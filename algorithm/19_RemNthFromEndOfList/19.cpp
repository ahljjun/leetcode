/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //use two pointers.
    //one pointer goes first with n steps
    // then , the second pointer begin to go
    
    ListNode* p = head;
    while(p && n) {
        p = p->next;
        --n;
    }
    
    if (n>0) {
        // the list length is less than n
        return head;
    }
    
    if (n==0 && !p) {
        // the head is the Nth
        return head->next;
    }
    
    assert(n==0 && p);
    
    ListNode *q = head;
    while(p->next) {
        q = q->next;
        p=p->next;
    }
    
    assert(q->next);
    q->next = q->next->next;
    
    return head; 
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
[1,2]
1
Output:
[2]
Expected:
[1]
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head;
    ListNode *pN  = NULL;
    // need to find the node prev to Nth.
    while(p && n--){
        p = p->next;
    }

    //case 1: the removed one is the head
    //case 2: the nth is  more than the list length
    //case 3: normal case
    if ( n>0 )
        return head;

    if ( !p )
        return head->next;

    pN = head;
    while(p && p->next){
        p= p->next;
        pN = pN->next;
    }
        
    pN->next = pN->next->next;
    return head;
}







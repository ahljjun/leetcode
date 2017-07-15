/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if ( !l1 )
        return l2;
    if (!l2)
        return l1;
    
    ListNode *p1, *p2, *p, *head;
    if (l1->val < l2->val){
        head = l1;
        p = l1;
        p1 = l1->next;
        p2 = l2;
    }else{
        head = l2;
        p = l2;
        p2 = l2->next;
        p1 = l1;
    }
        
    while( p1 && p2 ){
        if (p1->val < p2->val){
            ListNode *p1Next = p1->next;
            p->next = p1;
            p = p1;
            p1 = p1Next;
        }else{
            ListNode *p2Next = p2->next;
            p->next = p2;
            p = p2;
            p2 = p2Next;
        }
    }
        
    if ( p1 ){
        p->next = p1;
    }
        
    if (p2){
        p->next = p2;
    }
        
    return head;
}





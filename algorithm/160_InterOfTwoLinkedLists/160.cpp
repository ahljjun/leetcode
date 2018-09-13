/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

// needs O(1) memory , that means we could not use hashmap 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// copied from problem 142.cpp
 ListNode *detectCycle(ListNode *head) {
    if (head == NULL) return NULL;
    // use the slow/fast pointer to find the first meeting node
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast && (slow != fast)) {
        slow = slow->next;
        if ( fast->next ) {
            fast = fast->next->next;
        } else {
            // fast->next first meet the tail, no circle
            fast = fast->next;
        }
    }
    
    if (!fast) {
        return NULL;
    }

    // this means circle exists and slow == fast
    assert(slow == fast);
    slow = slow->next; // ATTENTION: need to advanced slow pointer first
    ListNode* p = head;
    while(p!=slow) {
        p = p->next;
        slow = slow->next;
    }

    return p;
}

// Extended from Rings of LinkedList. we can make rings
// say , we linked the c3->b1 , we create the ring.
// the problem now becomes : find the entry of the ring.
// after find. we can break the ring.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    //step1: first we make linked list B as the ring by concat the tail to head
    ListNode* tailB = headB;
    while(tailB->next) {
        tailB = tailB->next;
    }

    assert(tailB->next == NULL);
    // link  headB <---> tailB
    tailB->next = headB;

    //step2: find the ring by traversing from ListA
    ListNode* ringEntry = detectCycle(headA);

    //Step3: break the ring, restore
    tailB->next = NULL;

    //
    return ringEntry;
}


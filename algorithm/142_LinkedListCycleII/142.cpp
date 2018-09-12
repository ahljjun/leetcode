/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1: use hashMap.
// Pros: easy to understand
// Cons: cost extra space
ListNode *detectCycle(ListNode *head) {
    std::map<ListNode*, bool> nodeMap;
    ListNode* p = head;
    while(p) {
        if(nodeMap.find(p) != nodeMap.end()) {
            return p;
        }

        nodeMap.insert(std::make_pair(p, true));
        p = p->next;
    }

    return NULL;
}

// Solution 2: use fast/slow pointers.
// Pros: no extra space
// Cons: not easy to understand
// solution:
// 
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
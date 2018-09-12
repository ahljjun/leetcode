/*
Given a linked list, determine if it has a cycle in it.

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

//solution 1: use hashMap
//Pros: easy to understand
//Cons: need extra space

bool hasCycle(ListNode *head) {
    std::map<ListNode*, bool> nodeMap;
    ListNode* p = head;
    while(p) {
        if (nodeMap.find(p) != nodeMap.end()) 
            return true;

        nodeMap.insert(std::make_pair(p, true));
        p = p->next;
    }

    return false;
}

// solution 2: use fast/slow pointers
// benefit: fast and use non-extra space
// 
/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // recursive 版本：
 // reverse时需要更改的信息是：
 //  curNode, nextNode.
class Solution {
public:
    ListNode* reverseList_recursive(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* nextNode = head->next; // record the nextNode first
        ListNode* newHead = reverseList_recursive(nextNode);
        nextNode->next = head;
        head->next = NULL;
        
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        /*
         1  2  3  4  5
         p  q
            p  q
               p  q
                  p  q
                     p  q
        */
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = NULL;

        while(q) {
            ListNode* qNext = q->next;
            q->next = p;
            p = q;
            q = qNext;
        }

        return p;
    }
};
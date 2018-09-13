/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //solution1:        
        //treated like MergeSort
        int size = lists.size();
        if (lists.size() <2 )
            return lists[0];

        //divide the lists into even part
        vector<ListNode*> firstHalfKthList;
        vector<ListNode*> secondHalfKthList;

        int i = 0;
        for(i=0; i<size/2; ++i) {
            firstHalfKthList.push_back(lists[i]);
        }

        for(; i<size; ++i) {
            secondHalfKthList.push_back(lists[i]);
        }

        ListNode* firstList = mergeKLists(firstHalfKthList);
        ListNode* secondList = mergeKLists(secondHalfKthList);
        
        return mergeTwoLists(firstList, secondList);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyNode(0);
        ListNode *p = &dummyNode;
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        while(p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }  
            p = p->next;
        }

        assert(!p1 || !p2);

        if (p1) {
            p->next = p1;
        } else {
            p->next = p2;
        }

        return dummyNode.next;
    }
};
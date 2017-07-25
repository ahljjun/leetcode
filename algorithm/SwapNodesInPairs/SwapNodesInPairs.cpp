
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 


#include <iostream>
using namespace std;

/*
ListNode* swapPairs(ListNode* head) 
{
    if ( head==NULL )
        return head;
    if ( head->next == NULL )
        return head;

    ListNode *p = head;
    ListNode *retListDummyHead =new ListNode(0);
    ListNode *pRetNode = retListDummyHead;
    while(p && p->next){
        pRetNode->next = p->next;
        pRetNode->next->next = p;
        pRetNode = p;
        p = p->next->next;
    }

    if (p)
        pRetNode->next =  p;

    return retListDummyHead->next;
}
*/



ListNode* swapPairs(ListNode* head) 
{
    if ( head==NULL )
        return head;
    if ( head->next == NULL )
        return head;

    ListNode *p = head;
    ListNode *retListDummyHead =new ListNode(0);
    ListNode *pRetNode = retListDummyHead;
    while(p && p->next){
        ListNode* pNext = p->next;
        ListNode* pNextNext = p->next->next;
        pRetNode->next = pNext;
        p->next = pNextNext;
        pRetNode->next->next = p;
        pRetNode = p;
        p = pNextNext;
    }

    if (p)
        pRetNode->next =  p;

    return retListDummyHead->next;
}

ListNode* createList(int n){
    ListNode *dummyHead = new ListNode(0);
    ListNode *p = dummyHead;
    for(int i=1; i<=n; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    return dummyHead->next;
}

void dumpList(ListNode *pList)
{
    for(ListNode *p=pList; p!=NULL; p=p->next)
        cout<<p->val<<"->";

    cout<<endl;
}

int main()
{
    ListNode *ll = createList(1);
    dumpList(ll);
    ListNode *retLL = swapPairs(ll);
    dumpList(retLL);
}



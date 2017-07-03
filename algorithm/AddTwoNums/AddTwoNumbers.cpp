
/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * */


/**
 *   Definition for singly-linked list.
 *   struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *   };
 *        */
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

void printList(ListNode *l)
{
	while(l){
		cout<<l->val<<",";
		l=l->next;
	}
	cout<<"\n";
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if ( l1 == NULL ) 
		return l2;
        if ( l2 == NULL )
		return l1;
	
	ListNode *p1 = l1;
	ListNode *p2 = l2;
	ListNode *pNode = NULL;
	ListNode *pNewNode = NULL;
	ListNode *head = NULL;
	int carry =0;
	int num = 0;
	while( p1 && p2 ){
		num = (p1->val + p2->val + carry) % 10;	
		carry = (p1->val + p2->val + carry)/10;
		pNewNode = new ListNode(num);	
		if ( pNode )
			pNode->next = pNewNode; 	
		else{
			head = pNewNode;
			pNode = head;
		}
		pNode = pNewNode;
		p1 = p1->next;
		p2 = p2->next;
	}

	ListNode *p = NULL;
	if ( p1 )
		p = p1;
	if (p2)
		p = p2;

	while( p ){	
		num = (p->val + carry) % 10;	
		carry = (p->val + carry) / 10;
		pNewNode = new ListNode(num);	
		pNode->next = pNewNode;
		pNode = pNewNode;
		p = p->next;
	}

	if ( carry ){
		cout<<"carry:"<<carry<<endl;
		pNewNode = new ListNode(carry);	
		pNode->next = pNewNode;
	}


	return head;
}

ListNode* getListFromInteger(int num)
{	
	ListNode *head = NULL;
	ListNode *pNode = NULL;
	ListNode *pCurNode = NULL;
	while(num){
		pNode =	new ListNode(num%10);
		if ( !pCurNode ){
			pCurNode = pNode;
			head = pCurNode;
		}
		else{
			pCurNode->next = pNode;
			pCurNode = pNode;
		}
		
		num = num/10;
	}

	return head;
}


int main()
{
	int a,b;
	cin >> a >> b;
	
	ListNode *l1 =getListFromInteger(a);
	ListNode *l2 =getListFromInteger(b);
	cout<<"l1:"<<endl;
	printList(l1);
	cout<<"l2:"<<endl;
	printList(l2);
	cout<<"l3:"<<endl;
	ListNode *l3 = addTwoNumbers(l1,l2);
	printList(l3);

}




class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			            
		}
};

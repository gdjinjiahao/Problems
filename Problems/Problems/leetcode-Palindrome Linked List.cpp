/*
Given a singly linked list, determine if it is a palindrome.O(n) time and O(1) space.
分析：快慢指针找到中间节点，之后将链表从中间节点处断开，将后半部分反转，依次比较即可。
*/

#include <cstdlib>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head->next == NULL) return head;
		ListNode* l = head;
		ListNode* m = head;
		ListNode* r = head->next;
		while (r) {
			//此处若写m=m->next则会错误，原因是之后的步骤中会把m->next=l，第二次循环是m就会只想head指向的节点，从而错误。
			m = r;
			r = r->next;
			m->next = l;
			l = m;
		}
		head->next = NULL;
		return m;
	}

	bool isPalindrome(ListNode* head) {
		if (head == NULL) return true;
		if (head->next == NULL) return true;
		ListNode* f = head;
		ListNode* s = head;
		ListNode* pre = NULL;
		int n = 1;
		while (f->next) {
			pre = s;
			s = s->next;
			f = f->next;
			if (f == NULL) break;
			n++;
			f = f->next;
			if (f == NULL) break;
			n++;
		}
		pre->next = NULL;
		if (n & 1) s = s->next;
		ListNode* l1 = head;
		ListNode* l2 = reverseList(s);
		while (l1) {
			if (l1->val != l2->val) return false;
			l1 = l1->next;
			l2 = l2->next;
		}
		return true;
	}
};
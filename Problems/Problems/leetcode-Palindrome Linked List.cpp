/*
Given a singly linked list, determine if it is a palindrome.O(n) time and O(1) space.
����������ָ���ҵ��м�ڵ㣬֮��������м�ڵ㴦�Ͽ�������벿�ַ�ת�����αȽϼ��ɡ�
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
			//�˴���дm=m->next������ԭ����֮��Ĳ����л��m->next=l���ڶ���ѭ����m�ͻ�ֻ��headָ��Ľڵ㣬�Ӷ�����
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
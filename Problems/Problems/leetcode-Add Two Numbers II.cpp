/*
题意：给定两个链表，表示两个数字，不能修改这两个链表，求这两个数字的和，返回链表，链表从表头到表尾依次是数字的高位到低位
分析：提取每位数字保存在数组中，反转，相加，从后往前读取并构造链表即可
*/
#include <cstdlib>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		char a[300], b[300];
		int la = 0, lb = 0;
		for (int i = 0; i<300; i++) a[i] = b[i] = 0;
		while (l1) {
			a[la++] = l1->val;
			l1 = l1->next;
		}
		while (l2) {
			b[lb++] = l2->val;
			l2 = l2->next;
		}
		int l = 0, r = la - 1;
		while (l<r) {
			int t = a[l];
			a[l] = a[r];
			a[r] = t;
			l++; r--;
		}
		l = 0; r = lb - 1;
		while (l<r) {
			int t = b[l];
			b[l] = b[r];
			b[r] = t;
			l++; r--;
		}
		int t = 0;
		for (int i = 0; i<300; i++) {
			a[i] = a[i] + b[i] + t;
			t = a[i] / 10;
			a[i] %= 10;
		}
		int pos = 300 - 1;
		while (pos>0 && a[pos] == 0) pos--;
		ListNode* l3;
		ListNode* cur;
		l3 = new ListNode(a[pos--]);
		cur = l3;
		while (pos >= 0) {
			ListNode* tt;
			tt = new ListNode(a[pos--]);
			cur->next = tt;
			cur = tt;
		}
		return l3;
	}
};
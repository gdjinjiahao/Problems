/*
题意：给定一个链表，将索引号为奇数的放在一起且相对位置不变，将索引编号为偶数的放在后边，相对顺序不变，要求以O(1)的空间复杂度和O(n)的时间复杂度。
分析：将原链表拆成两个链表，最后合并即可，但注意边界情况。
*/
#include <cstdlib>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* l1 = NULL;
		ListNode* l2 = NULL;
		ListNode* cur1 = NULL;
		ListNode* cur2 = NULL;
		ListNode* pos = head;
		int i = 1;
		while (pos != NULL) {
			ListNode* next = pos->next;
			if (i & 1) {
				if (cur1 == NULL) {
					cur1 = l1 = pos;
					cur1->next = NULL;
				}
				else {
					pos->next = NULL;
					cur1->next = pos;
					cur1 = pos;
				}
			}
			else {
				if (cur2 == NULL) {
					cur2 = l2 = pos;
					pos->next = NULL;
				}
				else {
					pos->next = cur2->next;
					cur2->next = pos;
					cur2 = pos;
				}
			}
			pos = next;
			i++;
		}
		if (l1 == NULL) return NULL;
		cur1->next = l2;
		return l1;
	}
};
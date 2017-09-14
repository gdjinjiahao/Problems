/*
���⣺����һ��������������Ϊ�����ķ���һ�������λ�ò��䣬���������Ϊż���ķ��ں�ߣ����˳�򲻱䣬Ҫ����O(1)�Ŀռ临�ӶȺ�O(n)��ʱ�临�Ӷȡ�
��������ԭ�����������������ϲ����ɣ���ע��߽������
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
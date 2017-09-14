/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

分析：将之后每个元素前移。
*/

#include <cstdlib>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* pos = node->next;
		while (pos) {
			node->val = pos->val;
			if (pos->next == NULL)
				node->next = NULL;
			node = pos;
			pos = node->next;
		}
		delete node;
	}
};
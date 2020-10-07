/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return NULL;

		int len = 0;
		ListNode* node = head;
		ListNode* prev;

		while (node) prev = node, node = node->next, len = len + 1;

		prev->next = head;                 //make the list circular
		int leftstrt = len - k % len;      //find the start from left and make prev node to start NULL
		node = head;

		while (leftstrt--) prev = node, node = node->next;

		prev->next = NULL;

		return node;

	}
};
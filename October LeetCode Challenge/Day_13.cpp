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
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		if (head->next == nullptr) {
			return head;
		}
		pair<ListNode*, ListNode*> p = cutList(head);
		ListNode* left = p.first;
		ListNode* right = p.second;
		ListNode* left_sorted = sortList(left);
		ListNode* right_sorted = sortList(right);
		return merge(left_sorted, right_sorted);
	}

	ListNode* merge(ListNode* &node1, ListNode* &node2) {
		ListNode* head = nullptr;
		ListNode* tail = nullptr;
		while (node1 || node2) {

			if (!node1) {

				ListNode* next = node2->next;
				push_back(head, tail, node2);
				node2 = next;

			} else if (!node2) {

				ListNode* next = node1->next;
				push_back(head, tail, node1);
				node1 = next;
			} else {

				if (node1->val < node2->val) {
					ListNode* next = node1->next;
					push_back(head, tail, node1);
					node1 = next;
				} else {
					ListNode* next = node2->next;
					push_back(head, tail, node2);
					node2 = next;
				}
			}
		}
		return head;
	}

	void push_back(ListNode* &head, ListNode* &tail, ListNode* &node) {
		if (head == nullptr) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
			tail->next = nullptr;
		}
	}

	pair<ListNode*, ListNode*> cutList(ListNode* &head) {
		ListNode* prev_slow = head;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			prev_slow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev_slow->next = nullptr;
		return {head, slow};
	}
};
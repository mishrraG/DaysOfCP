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
	ListNode* ansHead;
	pair<int, int> addHelper(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr) {
			return make_pair(0, 0);
		}
		pair<int, int> a = addHelper(l1->next, l2->next);
		int sum = l1->val + l2->val + a.second;
		int r = sum % 10;
		ListNode* out = new ListNode(r);
		if (ansHead == nullptr) {
			ansHead = out;
		} else {
			out->next = ansHead;
			ansHead = out;
		}
		int c = sum / 10;
		return make_pair(r, c);
	}
	int addRemaining(ListNode* l, int d, int pC) {
		if (d == 1) {
			int sum = l->val + pC;
			int c = sum / 10;
			ListNode* out = new ListNode(sum % 10);
			out->next = ansHead;
			ansHead = out;
			pC = 0;
			return c;
		}
		int c = addRemaining(l->next, --d, pC);
		int sum = l->val + c;
		c = sum / 10;
		ListNode* out = new ListNode(sum % 10);
		out->next = ansHead;
		ansHead = out;
		return c;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode* lh1 = l1;
		ListNode* lh2 = l2;
		while (lh1 != nullptr && lh2 != nullptr) {
			lh1 = lh1->next;
			lh2 = lh2->next;
		}
		int diffLen = 0;
		if (lh1 == nullptr and lh2 == nullptr) {
			lh1 = l1;
			lh2 = l2;
			pair<int, int> a = addHelper(lh1, lh2);
			if (a.second != 0) {
				ListNode* out = new ListNode(a.second);
				out->next = ansHead;
				ansHead = out;
			}
		} else if (lh2 == nullptr) {
			while (lh1 != nullptr) {
				lh1 = lh1->next;
				diffLen++;
			}
			lh1 = l1;
			lh2 = l2;
			int x = diffLen;
			while (x > 0) {
				lh1 = lh1->next;
				x--;
			}


			pair<int, int> a = addHelper(lh1, lh2);
			lh1 = l1;
			int fC = addRemaining(lh1, diffLen, a.second);
			if (fC != 0) {
				ListNode* out = new ListNode(fC);
				out->next = ansHead;
				ansHead = out;
			}

		} else if (lh1 == nullptr) {
			while (lh2 != nullptr) {
				lh2 = lh2->next;
				diffLen++;
			}
			lh1 = l1;
			lh2 = l2;
			int x = diffLen;
			while (x > 0) {
				lh2 = lh2->next;
				x--;
			}


			pair<int, int> a = addHelper(lh1, lh2);
			lh2 = l2;
			int fC = addRemaining(lh2, diffLen, a.second);
			if (fC != 0) {
				ListNode* out = new ListNode(fC);
				out->next = ansHead;
				ansHead = out;
			}
		}

		return ansHead;
	}
};
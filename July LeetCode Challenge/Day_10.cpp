/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
	Node* flatten(Node* head) {
		if (!head) return NULL;
		Node* trav = head;
		while (trav) {
			if (trav->child) {
				Node* next = trav->next;
				Node* child = flatten(trav->child);
				trav->child = NULL;
				trav->next = child;
				child->prev = trav;
				Node* lastNode = child;
				while (lastNode->next) lastNode = lastNode->next;
				lastNode->next = next;
				if (next) next->prev = lastNode;
			}
			trav = trav->next;
		}
		return head;
	}
};
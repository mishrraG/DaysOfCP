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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        std::vector<ListNode*> nodes;
        ListNode* l2 = head;
        while (l2) {
            nodes.push_back(l2);
            l2 = l2->next;
        }
        if (nodes.size() == 2) return;
        int low = 1;
        int high = int(nodes.size()) - 1;
        while (low <= high) {
            nodes[low - 1]->next = nodes[high];
            nodes[high]->next = nodes[low];
            ++low;
            --high;
        }
        nodes[low - 1]->next = nullptr;
    }
};
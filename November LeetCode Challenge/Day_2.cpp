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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr ) {
            return nullptr ;
        }
        vector<ListNode*>nodes;
        nodes.push_back(head);
        ListNode*temp = head->next ;
        while (temp != nullptr ) {
            nodes.push_back(temp);
            for (int i = nodes.size() - 1 ; i > 0 ; i -- ) {
                if ( nodes[i]->val < nodes[i - 1]->val ) {
                    swap(nodes[i - 1]->val , nodes[i]->val);
                }
                else {
                    break;
                }
            }
            temp = temp->next;
        }
        return head ;
    }
};
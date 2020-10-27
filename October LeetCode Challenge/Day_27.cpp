/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:

    ListNode *detectCycle(ListNode *head) {

        if (head == NULL or head->next == NULL)
        {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        int x = 1;
        while ((fast and fast->next and fast != slow) or x)
        {
            slow = slow->next;
            fast = fast->next->next;
            x = 0;
        }

        if (!fast or !fast->next)
        {
            return NULL;
        }

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        cout << slow->val;

        return slow;

    }
};
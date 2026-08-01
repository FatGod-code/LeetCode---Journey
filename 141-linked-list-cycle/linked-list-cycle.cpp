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
    bool hasCycle(ListNode *head)
    {
        if (!head) { return false; }

        auto slow = head;
        auto quick = head;
        while (quick && quick->next)
        {
            slow = slow->next;
            quick = quick->next->next;

            if (slow==quick) { return true; }
        }

        return false;
    }
};
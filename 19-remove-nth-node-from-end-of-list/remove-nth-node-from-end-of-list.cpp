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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto dummy = new ListNode(-1, head);

        auto ptr = head;
        for (int i = 1; i<n; ++i) { ptr = ptr->next; }

        auto target = head;
        auto last = dummy;
        while (ptr && ptr->next)
        {
            ptr = ptr->next;
            last = target;
            target = target->next;
        }

        last->next = target->next;
        delete target;

        return dummy->next;
    }
};
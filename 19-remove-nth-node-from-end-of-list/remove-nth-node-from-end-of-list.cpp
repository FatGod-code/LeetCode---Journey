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

        auto fast = dummy;
        for (int i = 0; i<=n; ++i) { fast = fast->next; }

        auto slow = dummy;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        auto temp = slow->next->next;
        delete slow->next;
        slow->next = temp;

        return dummy->next;
    }
};
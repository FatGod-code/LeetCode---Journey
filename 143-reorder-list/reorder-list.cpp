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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next) { return; }

        ListNode* last = nullptr;
        auto slow = head;
        auto quick = head;
        while (quick && quick->next)
        {
            last = slow;
            slow = slow->next;
            quick = quick->next->next;
        }

        last->next = nullptr;

        last = nullptr;
        while (slow)
        {
            auto nextNode = slow->next;
            slow->next = last;
            last = slow;
            slow = nextNode;
        }

        ListNode dummy;
        auto tail = &dummy;
        bool useFirst = true;
        while (head && last)
        {
            if (useFirst)
            {
                tail->next = head;
                head = head->next;
            }
            else
            {
                tail->next = last;
                last = last->next;
            }
            tail = tail->next;
            useFirst = !useFirst;
        }

        tail->next = head ? head : last;

        head = dummy.next;
    }
};
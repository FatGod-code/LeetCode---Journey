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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || !head->next) { return head; }

        ListNode dummy(INT_MIN);
        auto tail = &dummy;

        auto ptr = head;
        while (ptr)
        {
            auto start = ptr;
            for (int c = 0; c<k; ++c)
            {
                if (ptr) { ptr = ptr->next; }
                else
                {
                    tail->next = start;
                    return dummy.next;
                }
            }

            tail->next = ReverseList(start, ptr);
            tail = start;
        }

        return dummy.next;
    }

    ListNode* ReverseList(ListNode* start, ListNode* end)
    {
        ListNode* last = nullptr;
        while (start!=end)
        {
            auto nextNode = start->next;
            start->next = last;
            last = start;
            start = nextNode;
        }

        return last;
    }
};
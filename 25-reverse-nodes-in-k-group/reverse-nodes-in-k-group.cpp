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

        ListNode* results = nullptr;
        ListNode* last = nullptr;
        ListNode* ptr = head;
        while (ptr)
        {
            bool runReverse = true;
            auto start = ptr;
            for (int c = 0; c<k; ++c)
            {
                if (ptr) { ptr = ptr->next; }
                else
                {
                    runReverse = false;
                    break;
                }
            }
            
            auto firstNode = start;
            if (runReverse) { firstNode = ReverseList(start, ptr); }

            if (last) { last->next = firstNode; }
            last = start;

            if (!results) { results = firstNode; }
        }

        return results;
    }

    ListNode* ReverseList(ListNode* start, ListNode* end)
    {
        ListNode* last = nullptr;
        while (start!=end)
        {
            auto next = start->next;
            start->next = last;
            last = start;
            start = next;
        }

        return last;
    }
};
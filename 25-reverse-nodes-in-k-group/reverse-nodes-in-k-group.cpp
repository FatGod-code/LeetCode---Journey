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
            
            auto head = start;
            std::pair<ListNode*, ListNode*> headTailPair{nullptr, nullptr};
            if (runReverse)
            {
                headTailPair = ReverseList(start, ptr);
                head = headTailPair.first;
            }

            if (last) { last->next = head; }
            last = headTailPair.second;

            if (!results) { results = headTailPair.first; }
        }

        return results;
    }

    std::pair<ListNode*, ListNode*> ReverseList(ListNode* start, ListNode* end)
    {
        std::pair<ListNode*, ListNode*> headTailPair;
        headTailPair.second = start;

        ListNode* last = nullptr;
        while (start!=end)
        {
            auto next = start->next;
            start->next = last;
            last = start;
            start = next;
        }

        headTailPair.first = last;
        return headTailPair;
    }
};
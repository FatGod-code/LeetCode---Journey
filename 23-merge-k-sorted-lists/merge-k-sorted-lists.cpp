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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        auto cmp = [](ListNode* a, ListNode* b)
        {
            return a->val>b->val;
        };

        ListNode dummy;
        auto tail = &dummy;
    
        std::vector<ListNode*> vec;
        vec.reserve(lists.size());
        for (const auto ele :lists)
        {
            if (ele) { vec.emplace_back(ele); }
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pque(cmp, std::move(vec));

        while (!pque.empty())
        {
            auto top = pque.top();
            pque.pop();

            tail->next = top;
            tail = tail->next;
            if (top->next) { pque.emplace(top->next); }
        }

        return dummy.next;
    }
};
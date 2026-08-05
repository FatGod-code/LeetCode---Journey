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
        if (lists.empty()) { return nullptr; }

        int size = lists.size();
        while (size)
        {
            if (size==1) { break; }

            for (int idx = 0; idx<size/2; ++idx)
            {
                auto ptr = SortTwoLists(lists[idx], lists[size-1-idx]);
                lists[idx] = ptr;
            }
            size = size/2 +size%2;
        }

        return lists.front();
    }

    ListNode* SortTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1 || !l2) { return l1 ? l1 : l2; }

        ListNode dummy;
        auto tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val<l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

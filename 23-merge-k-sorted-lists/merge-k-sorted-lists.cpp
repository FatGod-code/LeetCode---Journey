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

        return MergeListsRecur(lists, 0, lists.size());
    }

    ListNode* MergeListsRecur(std::vector<ListNode*>& lists, int start, int end)
    {
        if (start==end) { return nullptr; }
        if (start+1==end) { return lists[start]; }

        int middle = start+(end-start)/2;
        auto left = MergeListsRecur(lists, start, middle);
        auto right = MergeListsRecur(lists, middle, end);

        return SortTwoList(left, right);
    }

    ListNode* SortTwoList(ListNode* left, ListNode* right)
    {
        if (!left || !right) { return left ? left : right; }

        ListNode dummy;
        auto tail = &dummy;

        while (left && right)
        {
            auto leftValue = left->val;
            auto rightValue = right->val;
            if (leftValue<rightValue)
            {
                tail->next = left;
                tail = tail->next;
                left = left->next;
            }
            else
            {
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }
        }

        tail->next = left ? left : right;

        return dummy.next;
    }
};
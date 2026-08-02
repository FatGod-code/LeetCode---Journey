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
        mNode = head;
        mReturn = false;

        ReorderListRecur(head);
    }

    void
    ReorderListRecur(ListNode* node)
    {
        if (!node) { return; }

        ReorderListRecur(node->next);

        if (mReturn) { return; }
        if (mNode==node || mNode->next==node)
        {
            mReturn = true;
            node->next = nullptr;
            return;
        }

        auto nextNode = mNode->next;
        node->next = mNode->next;
        mNode->next = node;

        mNode = nextNode;
    }

private:
    ListNode* mNode;
    bool mReturn;
};
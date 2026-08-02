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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1 || !list2) { return list1 ? list1 : list2; }

        auto ptr1 = list1;
        auto ptr2 = list2;
        ListNode* last = nullptr;
        while (ptr1 && ptr2)
        {
            int value1 = ptr1->val;
            int value2 = ptr2->val;

            if (value1<value2)
            {
                while (ptr1->next && ptr1->next->val<value2) { ptr1 = ptr1->next; }

                auto nextNode = ptr1->next;
                ptr1->next = ptr2;
                last = ptr1;
                ptr1 = nextNode;
            }
            else
            {
                while (ptr2->next && ptr2->next->val<=value1) { ptr2 = ptr2->next; }

                auto nextNode = ptr2->next;
                ptr2->next = ptr1;
                last = ptr2;
                ptr2 = nextNode;
            }
        }

//        if (ptr1) { last->next = ptr1; }
//        else if (ptr2) { last->next = ptr2; }

        return list1->val<list2->val ? list1 : list2;
    }
};
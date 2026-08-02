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
        
        ListNode* dummy = new ListNode();
        auto tail = dummy;

        auto ptr1 = list1;
        auto ptr2 = list2;
        while (ptr1 && ptr2)
        {
            int value1 = ptr1->val;
            int value2 = ptr2->val;
            
            if (value1<value2)
            {
                tail->next = ptr1;
                tail = tail->next;
                ptr1 = ptr1->next;
            }
            else
            {
                tail->next = ptr2;
                tail = tail->next;
                ptr2 = ptr2->next;
            }
        }

        tail->next = ptr1 ? ptr1 : ptr2;

        return dummy->next;

    }
};
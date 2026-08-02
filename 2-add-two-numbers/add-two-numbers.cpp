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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto ptr1 = l1;
        auto ptr2 = l2;
        ListNode* last = nullptr;
        int carry = 0;
        while (ptr1 && ptr2)
        {
            int sum = ptr1->val+ptr2->val+carry;
            int value = sum%10;
            carry = sum/10;
            
            last = ptr1;
            ptr1->val = value;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr2)
        {
            last->next = ptr2;
            while (carry)
            {
                if (ptr2)
                {
                    int sum = ptr2->val+carry;
                    int value = sum%10;
                    carry = sum/10;
                    ptr2->val = value;

                    last = ptr2;
                    ptr2 = ptr2->next;
                }
                else
                {
                    last->next = new ListNode(1);
                    break;
                }
            }
        }
        else if (ptr1)
        {
            while (carry)
            {
                if (ptr1)
                {
                    int sum = ptr1->val+carry;
                    int value = sum%10;
                    carry = sum/10;
                    ptr1->val = value;

                    last = ptr1;
                    ptr1 = ptr1->next;
                }
                else
                {
                    last->next = new ListNode(1);
                    break;
                }
            }
        }
        else
        {
            if (carry) { last->next = new ListNode(1); }
        }

        return l1;
    }
};
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
        ListNode dummy;
        auto tail = &dummy;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1) { sum += l1->val; }
            if (l2) { sum += l2->val; }
            if (carry) { sum += carry; }

            int value = sum%10;
            carry = sum/10;
        
            if (l1)
            {
                l1->val = value;
                tail->next = l1;
            }
            else if (l2)
            {
                l2->val = value;
                tail->next = l2;
            }
            else
            {
                tail->next = new ListNode(1);
            }

            tail = tail->next;

            if (l1) { l1 = l1->next; }
            if (l2) { l2 = l2->next; }
        }

        return dummy.next;
    }
};
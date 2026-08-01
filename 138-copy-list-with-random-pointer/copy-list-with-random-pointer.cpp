/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) { return nullptr; }

        for (auto ptr = head; ptr; ptr = ptr->next->next)
        {
            auto newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
        }

        for (auto ptr = head; ptr; ptr = ptr->next->next)
        {
            if (ptr->random) { ptr->next->random = ptr->random->next; }
            else { ptr->next->random = nullptr; }
        }

        auto results = head->next;
        for (auto ptr = head; ptr; ptr = ptr->next)
        {
            auto nextNode = ptr->next;
            ptr->next = nextNode->next;

            if (nextNode->next) { nextNode->next = nextNode->next->next; }
            else nextNode->next = nullptr;
        }

        return results;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (!node) { return nullptr; }

        std::unordered_map<Node*, Node*> visited;

        Node* results = new Node(node->val);
        visited.emplace(node, results);
        
        std::queue<Node*> que;
        que.push(node);
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto node = que.front();
                que.pop();

                for (const auto neighbor : node->neighbors)
                {
                    Node* ptr = nullptr;

                    auto found = visited.find(neighbor);
                    if (found==visited.end())
                    {
                        ptr = new Node(neighbor->val);
                        visited.emplace(neighbor, ptr);
                        que.push(neighbor);
                    }
                    else { ptr = found->second; }

                    visited[node]->neighbors.emplace_back(ptr);
                }
            }
        }

        return results;
    }
};
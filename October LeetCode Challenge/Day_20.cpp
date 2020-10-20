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
    Node* rec(Node* node) {
        if (m_map.find(node->val) != m_map.end())
            return m_map[node->val];

        Node* new_node = new Node(node->val);
        m_map[node->val] = new_node;
        for (auto neighbor : node->neighbors)
            new_node->neighbors.push_back(rec(neighbor));
        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        return rec(node);
    }

private:
    unordered_map<int, Node*> m_map;
};
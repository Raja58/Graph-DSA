// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        Clone Graph (LeetCode)
//  ============================
//  -->

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
    vector<Node *> clonedNodes{101, NULL};
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(clonedNodes[node -> val] != NULL)
            return clonedNodes[node -> val];
        
        Node *clone = new Node(node -> val);
        clonedNodes[node -> val] = clone;
        for(Node *x : node -> neighbors)
            clone -> neighbors.push_back(cloneGraph(x));
        return clone;
    }
};

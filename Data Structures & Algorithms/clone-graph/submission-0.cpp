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

    Node* DFSclone(Node* root, unordered_map<Node*,Node*> & visited) {
        if(!root){
            return nullptr;
        }

        if(visited.contains(root)){
            return visited[root];
        }

        Node* copy = new Node(root->val,root->neighbors);
        visited[root] = copy;

        for(int i = 0; i < root->neighbors.size();i++) {
            copy->neighbors[i] = DFSclone(root->neighbors[i],visited);
        }

        return copy;

    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> visited;
        return DFSclone(node, visited);
    }
};

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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> old_to_new;
        queue<Node*> q;

        if(node == nullptr)
            return nullptr;

        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(old_to_new.find(curr) == old_to_new.end()){ //value hasn't been created yet
                old_to_new[curr] = new Node(curr->val);
            }

            for(const auto& n : curr->neighbors){
                if(old_to_new.find(n) == old_to_new.end()){
                    old_to_new[n] = new Node(n->val);
                    q.push(n);
                }
                old_to_new[curr]->neighbors.push_back(old_to_new[n]);
            }
        }

        return old_to_new[node];

    }
};

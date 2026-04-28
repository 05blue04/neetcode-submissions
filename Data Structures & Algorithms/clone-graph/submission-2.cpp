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
        unordered_map<Node*, Node*> old_to_new;
        unordered_set<int> visit;
        queue<Node*> q;

        if(node == nullptr)
            return node;
        
        q.push(node);

        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            
            if(visit.count(n->val))
                continue;
            
            visit.insert(n->val);

            if(old_to_new.find(n) == old_to_new.end()){
                old_to_new[node] = new Node(n->val);
            }

            for(const auto& nei : n->neighbors){
                if(old_to_new.find(nei) == old_to_new.end()){
                    old_to_new[nei] = new Node(nei->val);
                }

                old_to_new[n]->neighbors.push_back(old_to_new[nei]);
                q.push(nei);
            }
        }
        return old_to_new[node];
    }
};

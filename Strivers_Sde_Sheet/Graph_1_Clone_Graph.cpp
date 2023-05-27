//Solution 1 --> Concept of Dfs travesal with S.C{O(V+E)}, T.C{O(V)}
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
    Node* dfs(Node* curr, unordered_map<Node*, Node*>& mp)
    {

            vector<Node* > neighbor;
            Node* clone = new Node(curr->val);
            mp[curr] = clone;

                    for(auto it: curr->neighbors)
                    {
                            if(mp.find(it) != mp.end())
                            {
                                neighbor.push_back(mp[it]);
                            }
                            else
                            {
                                neighbor.push_back(dfs(it, mp));
                            }

                    }
            
            clone->neighbors = neighbor;
            return clone;

    }
    Node* cloneGraph(Node* node) {

            unordered_map<Node*, Node*>mp;
            if(node== NULL)
                return NULL;
            if(node->neighbors.size()==0)
            {
                Node* clone = new Node(node->val);
                return clone;

            }

            return dfs(node, mp);

        
    }
};

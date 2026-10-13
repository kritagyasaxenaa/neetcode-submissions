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
        if(!node){
            return nullptr;
        }
        map<Node*,Node*> m;
        queue<Node*>q;
        q.push(node);
        set<Node*>s;
        s.insert(node);
        while(!q.empty()){
            Node* var=q.front();
            if(!m[var]){
                Node* temp=new Node(var->val);
                m[var]=temp;
            }
            for(Node* a:var->neighbors){
                if(s.find(a)==s.end()){
                    s.insert(a);
                    q.push(a);
                }
            }
            q.pop();
        }
        s.clear();
        s.insert(node);
        q.push(node);
        while(!q.empty()){
            Node* var=q.front();
            vector<Node*>v;
            for(Node* a:var->neighbors){
                v.push_back(m[a]);
                if(s.find(a)==s.end()){
                    q.push(a);
                    s.insert(a);
                }
            }
            m[var]->neighbors=v;
            q.pop();
        }
        return m[node];

    }
};

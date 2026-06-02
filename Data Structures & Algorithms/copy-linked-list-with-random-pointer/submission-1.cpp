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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* a=new Node(head->val);
        vector<Node*>og;
        map<Node*, Node*>n;
        n[nullptr]=nullptr;
        Node * temp=head;
        while(temp!=nullptr){
            og.push_back(temp->random);
            temp=temp->next;
        }
        temp=head->next;
        n[head]=a;
        Node * b= a;
        while(temp!=nullptr){
            b->next= new Node(temp->val);
            b=b->next;
            n[temp]=b;
            temp=temp->next;
        }
        b=a;
        int count=0;
        while(b!=nullptr){
            Node* c= og[count];
            b->random=n[c];
            count++;
            b=b->next;
        }
        return a;
    }
};

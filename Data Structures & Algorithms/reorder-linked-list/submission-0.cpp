/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
         stack <ListNode*> store;
    ListNode* curr=head;
    while(curr!=NULL){
        store.push(curr);
        curr=curr->next;    // reached Ln
    }
    curr= head;
    while(curr!=store.top()){
        ListNode* old= curr->next;  // store L2
        curr->next=store.top(); // use Ln
        store.pop();    // remove Ln
        curr=curr->next;    // move to Ln
        curr->next=old;     // next to Ln is L2
        if(curr->next==curr){
            break;
        }
        curr=curr->next;    // move to L2 
    }
    curr->next=nullptr; // if Li is top of stack, then next to Li must be null for it to end
    }
};
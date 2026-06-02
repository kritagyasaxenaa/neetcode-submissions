class Solution {
public:
    ListNode* reverseList(ListNode* head) {
           ListNode* curr = head;
    ListNode* prev=NULL;
    while (curr!=NULL){
        ListNode* nex =curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    head= prev;
    return head;
    }
};
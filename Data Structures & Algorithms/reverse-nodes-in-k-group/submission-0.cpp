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
    ListNode *ReverseBetween(ListNode *head, int left, int right) 
{
    ListNode* curr= head;
    ListNode* a;
    ListNode* b;
    ListNode* prev;
    ListNode* nex;
    ListNode* end;
    int count=1;
    a=NULL; // initially nothing before left
    while(count!=left){
     count++;   
     a=curr;        // find what is before left
     curr=curr->next;
    }
    // reached left
    ListNode* Left= curr;
    while(count!=right){
        count++;
        curr=curr->next;
    }
    ListNode* Right= curr;
    b=Right->next;
    if(a!=NULL){
        a->next=Right;
    }
    prev=b;
    curr= Left;
    end= Right->next;
    while(curr!=end){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    if(a==NULL){
        head=Right;
    }
    return head;
}
ListNode *reverseKGroup(ListNode *head, int k) {
  
    // Replace this placeholder return statement with your code
    ListNode* start=head;
    ListNode* curr=start;
    int left=1;
    int right=0;
    bool done=false;
    while(curr!=nullptr){
        left=right+1;
        start=curr;
        for(int i=0;i<k;i++){
            if(curr==nullptr){
                done=true;
                break;
            }
            curr=curr->next;
        }
        if(done){
            break;
        }
        right=left+k-1;
        head=ReverseBetween(head,left,right);
    }
    return head;
}
};
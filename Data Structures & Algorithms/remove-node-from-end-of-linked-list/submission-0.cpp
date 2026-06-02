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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp= head;
        stack<ListNode*>s;
        while(temp!=nullptr){
            s.push(temp);
            temp=temp->next;
        }
        //created a stack
        int count=1;
        while(count!=n){
            s.pop();
            count++;
        }
        ListNode* del=s.top();
        s.pop();
        if(del==head){
            head=del->next;
            return head;
        }
        ListNode* a=s.top();
        a->next=del->next;
        return head;
    }
};

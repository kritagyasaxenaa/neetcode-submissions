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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0, carry=0;
        int a=l1!=nullptr?l1->val:0;
        int b=l2!=nullptr?l2->val:0;
        sum=(a+b+carry)%10;
        carry=(a+b+carry)/10;
        l1=l1->next;
        l2=l2->next;
        ListNode* head=new ListNode(sum);
        ListNode*temp=head;
        while(l1!=nullptr||l2!=nullptr){
            a=l1!=nullptr?l1->val:0;
            b=l2!=nullptr?l2->val:0;
            sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            temp->next=new ListNode(sum,nullptr);
            temp=temp->next;
            if(l1!=nullptr){
                l1=l1->next;
            }
            if(l2!=nullptr){
                l2=l2->next;
            }
        }
        while(carry!=0){
            a=0,b=0;
            sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            temp->next=new ListNode(sum,nullptr);
            temp=temp->next;
        }
        return head;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        int min=list1->val<list2->val?list1->val:list2->val;
        ListNode* l1= new ListNode(min);
        ListNode* temp=l1;
        while(list1!=nullptr || list2!=nullptr){
            temp->next=new ListNode();
            temp=temp->next;
            if((list1==nullptr)||(list2!=nullptr&&list1->val>=list2->val)){
                temp->val=list2->val;
                list2=list2->next;
            }
            else{
                temp->val=list1->val;
                list1=list1->next;
            }
        }
        temp=l1->next;
        delete l1;
        return temp;

    }
};
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
        if(list1->val>list2->val){
            ListNode* var=list2;
            list2=list1;
            list1=var;
        }
        ListNode* l1= list1;
        while(list2!=nullptr){
            if(!l1){
                l1=list2;
                break;
            }
            else{
                while(l1->next!=nullptr&&list2->val>l1->next->val){
                    l1=l1->next;
                }
                if(l1->next==nullptr){
                    l1->next=list2;
                    break;
                }
                else{
                    //l2 < l1->next
                    ListNode*temp=list2;
                    list2=list2->next;
                    temp->next=l1->next;
                    l1->next=temp;
                }
            }
            
        }
        return list1;

    }
};
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
        vector <int> temp;
        for(auto it= list1; it!=nullptr; it=it->next){
            temp.push_back(it->val);
        }
        for(auto it= list2; it!=nullptr; it=it->next){
            temp.push_back(it->val);
        }
        sort(temp.begin(), temp.end());
        ListNode* l=nullptr;
        if(temp.size()==0){
            return l;
        }
        l=new ListNode;
        ListNode* l1=l;
        for(int i=0;i<temp.size();i++){
            l->val=temp[i];
            ListNode* NewVar=nullptr;
            if(i!=temp.size()-1){
                NewVar=new ListNode;
                NewVar->next=nullptr;
            }
            l->next=NewVar;
            l=l->next;
        }
        return l1;
    }
};
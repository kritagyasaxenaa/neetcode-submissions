/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                if(!q){
            return p;
        }
        if(!p){
            return q;
        }
        int a =p->val;
        int b=q->val;
        if(a==b){
            return p;
        }
        TreeNode* curr=root;
        while(curr){
            int c=curr->val;
            if((c>=a&&c<=b)||(c<=a&&c>=b)){
                return curr;
            }
            if(c<=a&&c<=b){
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        return root;
    }
};

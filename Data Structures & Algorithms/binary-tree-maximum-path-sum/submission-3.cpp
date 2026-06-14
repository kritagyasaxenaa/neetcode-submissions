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
    long long int mx=INT32_MIN;
    long long int PathSum(TreeNode* root){
        // for nodes that are not root
        if(!root){
            return INT32_MIN;
        }
        long long int l=PathSum(root->left);//contribution of left
        long long int r=PathSum(root->right);//contribution of right
        long long int v=root->val;    //contribution of parent
        long long int m=max(max(v+l,v+r),v);  // contribution to the parent
        mx=max(mx,max(m,v+l+r)); // max if it was the root  l, r would've been covered before
        return m;
    }

    int maxPathSum(TreeNode* root) {
        // my idea is to iterate as : left->parent->right 
        if(!root){
            return 0;
        }
        long long int m=PathSum(root);
        mx=max(m,mx);
        return (int)mx;
        
    }

};

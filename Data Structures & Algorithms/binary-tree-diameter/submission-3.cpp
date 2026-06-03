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
        int currDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(currDepth(root->left)+1, currDepth(root->right)+1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left=currDepth(root->left);
        int right=currDepth(root->right);
        int left1=diameterOfBinaryTree(root->left);
        int right1=diameterOfBinaryTree(root->right);
        int m=max(max(left,right), max(left1,right1));
        if(root->left&&root->right){
            m=max(m,left+right);
        }
        return m;

    }
};

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
    int currDepth(TreeNode* root, bool & ret) {
        if(!root){
            return 0;
        }
        int right=currDepth(root->right,ret);
        int left=currDepth(root->left,ret);
        if(abs(right-left)>1){
            ret=false;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ret=true;
        currDepth(root,ret);
        return ret;
    }
};

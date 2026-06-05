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
    void preOrder(TreeNode* root, vector<int>& ret){
        if(!root){
            return;
        }
        preOrder(root->left,ret);
        ret.push_back(root->val);
        preOrder(root->right,ret);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ret;
        preOrder(root,ret);
        return ret[k-1];
    }
};

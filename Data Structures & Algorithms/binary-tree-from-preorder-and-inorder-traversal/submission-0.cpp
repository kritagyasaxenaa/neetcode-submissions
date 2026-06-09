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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        TreeNode* root= new TreeNode(preorder[0]);
        int mid=find(inorder.begin(),inorder.end(),root->val)- inorder.begin();
        vector<int>ino, preo;
        for(int i=0;i<mid;i++){
            ino.push_back(inorder[i]);
        }
        for(int i=1;i<mid+1;i++){
            preo.push_back(preorder[i]);
        }
        root->left=buildTree(preo,ino);
        ino.clear();
        preo.clear();
        for(int i=mid+1;i<preorder.size();i++){
            ino.push_back(inorder[i]);
        }
        for(int i=mid+1;i<preorder.size();i++){
            preo.push_back(preorder[i]);
        }
        root->right=buildTree(preo,ino);
        preo.clear();
        ino.clear();
        return root;
    }
};

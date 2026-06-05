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
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ret;
    if(!root){
        return ret;
    }
    vector<vector<TreeNode*>>it;
    vector<TreeNode*>t={root};
    it.push_back(t);
    for(int i=0;i<it.size();i++){
        vector<TreeNode*>t1;
        vector<int>t2;
        for(int j=0;j<it[i].size();j++){
            TreeNode* var=it[i][j];
            if(var==nullptr){
                continue;
            }
            else{
                t1.push_back(var->left);
                t2.push_back(var->val);
                t1.push_back(var->right);
            }
        }
        if(!t1.empty())
            it.push_back(t1);
        if(!t2.empty())
            ret.push_back(t2);
    } 
    return ret;
}
};

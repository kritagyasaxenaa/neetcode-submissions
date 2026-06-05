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
    vector<int> rightSideView(TreeNode* root) {
        // simply return the last element of each level in bfs
        vector<int>ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int r=0;
            bool found=false;
            for(int i=0;i<n;i++){
                TreeNode* var=q.front();
                q.pop();
                if(!var){
                    continue;
                }
                else{
                    r=var->val;
                    found=true;
                    q.push(var->left);
                    q.push(var->right);
                }
            }
            if(found){
                ret.push_back(r);
            }
        }
        return ret;
    }
};

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
struct Bool{
        bool p=false;
        bool q=false;
    };
class Solution {
public:
    map<TreeNode*,Bool>m;
    TreeNode* Dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        stack<TreeNode*>dfs;
        stack<TreeNode*>dfs2;
        // check if p is the ancestor of q or q is the ancestor of p
        dfs.push(root);
        dfs2.push(root);
        while(!dfs.empty()){
            if(!dfs.top()){
                dfs.pop();
                continue;
            }
            else{
                TreeNode* temp=dfs.top();
                dfs.pop();
                dfs.push(temp->right);
                dfs.push(temp->left);
                dfs2.push(temp->right);
                dfs2.push(temp->left);
                if(temp->left==q||temp->right==q||temp==q){
                    m[temp].q=true;
                    // q in this node
                }
                if(temp->left==p||temp->right==p||temp==p){
                    m[temp].p=true;
                    // p in this node
                }
            }
        }
        while(!dfs2.empty()){
            if(!dfs2.top()){
                dfs2.pop();
            }
            else{
                TreeNode*temp=dfs2.top();
                if(m[temp->left].p||m[temp->right].p){
                    m[temp].p=true;
                }
                if(m[temp->left].q||m[temp->right].q){
                    m[temp].q=true;
                }
                if(m[temp].p&&m[temp].q){
                    return temp;
                }
                dfs2.pop();
            }
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return Dfs(root,p,q);

    }
};

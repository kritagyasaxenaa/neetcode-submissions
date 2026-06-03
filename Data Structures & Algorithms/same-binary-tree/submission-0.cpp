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
    bool isSameTree(TreeNode* p, TreeNode* q) {
     vector<TreeNode*>bfs;
     bfs.push_back(p);
    vector<TreeNode*>bfs2;
     bfs2.push_back(q);
     for(int i=0;i<bfs.size();i++){
       if(bfs[i]==nullptr&&bfs2[i]==nullptr){
            continue;
        }
        if(bfs[i]==nullptr||bfs2[i]==nullptr){
            return false;
        }
        else{
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            bfs2.push_back(bfs2[i]->left);
            bfs2.push_back(bfs2[i]->right);
        }
        
        if(bfs[i]->val!=bfs2[i]->val){
            return false;
        }
     }
     return true;
    }
};

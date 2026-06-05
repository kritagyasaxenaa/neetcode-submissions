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
    int goodNodes(TreeNode* root) {
        // simple implementation of dfs
        // store the root val and max, for each depth if the value is more than max it is good and max = curr, else continue
        int good=0;
        if(!root){
            return good;
        }
        int r=root->val;
        int max=-101;
        stack<TreeNode*>s;  // stores the node
        stack<int>m;    // stores the max value upto that node
        s.push(root);
        m.push(root->val);
        while(!s.empty()){
            TreeNode* a=s.top();
            max=m.top();    // retrieve the max value
            s.pop();
            m.pop();
            if(!a){
                continue;
            }
            if(a->val>=max){
                good++;
                max=a->val;
            }
            s.push(a->right);
            m.push(max);
            s.push(a->left);
            m.push(max);
        }
        return good;
    }
};

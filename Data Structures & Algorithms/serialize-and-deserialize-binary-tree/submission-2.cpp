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
class Codec {
public:

    vector<TreeNode*>BFS(TreeNode* p){
        vector<TreeNode*>bfs;
        bfs.push_back(p);
        for(int i=0;i<bfs.size();i++){
            if(bfs[i]==nullptr){
                continue;
            }
            else{
                bfs.push_back(bfs[i]->left);
                bfs.push_back(bfs[i]->right);
            }
        }
        return bfs;
    }
    string toString(int a){
        string s;
        while(a!=0){
            int b=a%10;
            char c='0'+ b;
            s+=c;
            a=a/10;
        }
        reverse(begin(s),end(s));
        return s;
    }

    int toInt(string s){
        int a=0;
        for(char i:s){
            a=a*10;
            a+=i-'0';
        }
        return a;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // i could simply use bfs
        vector<TreeNode*>bfs=BFS(root);
        string s;
        for(TreeNode* i: bfs){
            if(i==nullptr){
                s.append(",");
                s.append("nullptr");
            }
            else{
                s.append(",");
                s.append(toString(i->val));
            }
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        vector<TreeNode*>bfs;
        for(int i=1;i<data.size();i++){
            string b;
            while(i<data.size()&&data[i]!=','){
               b += data[i++];
            }
            if(b=="nullptr"){
                bfs.push_back(nullptr);
            }
            else{
                int a=toInt(b);
                TreeNode* temp=new TreeNode(a);
                bfs.push_back(temp);
            }
        }
        // found the bfs of the tree
        TreeNode* root=bfs[0];
        TreeNode* temp= root;
        for(int i=0,j=1;j<bfs.size();i++){
            if(bfs[i]==nullptr){
                continue;
            }
            bfs[i]->left=bfs[j];
            bfs[i]->right=bfs[j+1];
            j+=2;
        }
        return root;
    }
};

class Solution {
public:
    bool findIt(int i, int j,vector<vector<char>>& board,string &word, vector<char>&var )
    {
        if(i>=board.size()||i<0){
            return false;
        }
        if(j>=board[0].size()||j<0){
            return false;
        }
        if(board[i][j]==word[var.size()]){
            var.push_back(board[i][j]);
            board[i][j]+=100;
        }
        else{
            return false;
        }
        if(var.size()==word.size()){
            var.pop_back();
            return true;
        }
        bool ret=false;
        ret=ret|findIt(i+1,j,board,word,var);
        ret=ret|findIt(i,j+1,board,word,var);
        ret=ret|findIt(i,j-1,board,word,var);
        ret=ret|findIt(i-1,j,board,word,var);
        var.pop_back();
        board[i][j]-=100;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<char>var;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                bool ret= findIt(i,j,board,word,var);
                if(ret){
                    return true;
                }
            }
        }
        return false;
    }
};

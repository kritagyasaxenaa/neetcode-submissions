class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(vector <char> a: board){
            unordered_set<char> temp;
            for(char c: a){
                if(temp.find(c)!=nullptr){
                    return false;
                }
                if(c=='.'){
                    continue;
                }
                temp.insert(c);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> temp;
            for(vector<char>a:board){
                char c=a[i];
                if(temp.find(c)!=nullptr){
                    return false;
                }
                if(c=='.'){
                    continue;
                }
                temp.insert(c);
            }
        }
         unordered_set<char> temp1, temp2, temp3;
        for(int i=0;i<9;i++){
            if(i%3==0){
                    temp1.clear();
                    temp2.clear();
                    temp3.clear();
                }
            for(int j=0;j<3;j++){
                char c=board[i][j];
                 if(temp1.find(c)!=nullptr){
                    return false;
                }
                if(c=='.'){
                    continue;
                }
                temp1.insert(c);
            }
            for(int j=3;j<6;j++){
                char c=board[i][j];
                 if(temp2.find(c)!=nullptr){
                    return false;
                }
                if(c=='.'){
                    continue;
                }
                temp2.insert(c);
            }
            for(int j=6;j<9;j++){
                char c=board[i][j];
                 if(temp3.find(c)!=nullptr){
                    return false;
                }
                if(c=='.'){
                    continue;
                }
                temp3.insert(c);
            }
        }
        return true;
    }
};

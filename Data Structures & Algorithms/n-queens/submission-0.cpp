class Solution {
public:
    bool cross(vector<string>&var, int p, int q){
        if(var[p][q]=='x'){
            return false;
        }
        for(int i=p,j=q;i>=0&&j<var.size();i--,j++){
            if(var[i][j]=='Q'){
                return false;
            }
        }
        for(int i=p,j=q;i>=0&&j>=0;i--,j--){
            if(var[i][j]=='Q'){
                return false;
            }
        }
        for(int i=p,j=q;i<var.size()&&j<var.size();i++,j++){
            if(var[i][j]=='Q'){
                return false;
            }
        }
        for(int i=p,j=q;i<var.size()&&j>=0;i++,j--){
            if(var[i][j]=='Q'){
                return false;
            }
        }
        for(int i=p;i>=0;i--){
            if(var[i][q]=='Q'){
                return false;
            }
        }
        for(int i=p;i<var.size();i++){
            if(var[i][q]=='Q'){
                return false;
            }
        }
        for(int j=q;j>=0;j--){
            if(var[p][j]=='Q'){
                return false;
            }
        }
        for(int j=q;j<var.size();j++){
            if(var[p][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void simple(vector<string>&var, int p, int q){
        for(int i=p,j=q;i>=0&&j<var[0].size();i--,j++){
            var[i][j]='x';
        }
        for(int i=p,j=q;i>=0&&j>=0;i--,j--){
            var[i][j]='x';
        }
        for(int i=p,j=q;i<var.size()&&j<var[0].size();i++,j++){
            var[i][j]='x';
        }
        for(int i=p,j=q;i<var.size()&&j>=0;i++,j--){
            var[i][j]='x';
        }
        for(int i=p;i>=0;i--){
            var[i][q]='x';
        }
        for(int i=p;i<var.size();i++){
            var[i][q]='x';
        }
        for(int j=q;j>=0;j--){
            var[p][j]='x';
        }
        for(int j=q;j<var.size();j++){
            var[p][j]='x';
        }
        var[p][q]='Q';
        return;
    }
    void solve(int ind, vector<vector<string>>&ret, vector<string>&var, int n){
        if(ind >= n){
            ret.push_back(var);
            return;
        }
        vector<string>temp=var;
        for(int i=0;i<n;i++){
            if(cross(var,ind,i)){
                simple(var,ind,i);
                solve(ind+1,ret,var,n);
                var=temp;
            }
        }
        return;

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ret;
        vector<string>var;
        for(int i=0;i<n;i++){
            string temp(n,'.');
            var.push_back(temp);
        }
        solve(0,ret,var,n);
        for(int i=0;i<ret.size();i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(ret[i][j][k]=='x'){
                        ret[i][j][k]='.';
                    }
                }
            }
        }
        return ret;
    }
};

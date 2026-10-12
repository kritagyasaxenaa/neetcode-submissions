class Solution {
public:

    bool valid(string &a){
        stack<char>c;
        for(char s: a){
            if(s=='('){
                c.push(s);
            }
            else{
                if(c.empty()){
                    return false;
                }
                c.pop();
            }
        }
        if(!c.empty()){
            return false;
        }
        return true;
    }

    void genAll(vector<char>&arr,int i,vector<string>&ret, string &var){
        if(i==arr.size()){
            return;
        }
        if(arr[i]=='('+10||arr[i]==')'+10){
            return;
        }
        var.push_back(arr[i]);
        if(var.size()==arr.size()){
            if(valid(var))
                ret.push_back(var);
            var.pop_back();
            return;
        }
        arr[i]+=10;
            for(int j=0;j<arr.size();j++){
                if(arr[j]=='('||arr[j]==')'){
                    while(j<arr.size()-1&&arr[j]==arr[j+1]){
                    j++;
                }
                    genAll(arr,j,ret,var);
                }
            }
        arr[i]-=10;
        var.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        // brute is basically to generate a parentheses and search if it is valid;
        vector<char>arr(n,'(');
        for(int i=0;i<n;i++){
            arr.push_back(')');
        }
        //generate all strings
        string var;
        vector<string>ret;
        for(int i=0;i<arr.size();i++){
            while(i<arr.size()-1&&arr[i]==arr[i+1]){
                    i++;
                }
            genAll(arr,i,ret,var);
        }
        return ret;
    }
};

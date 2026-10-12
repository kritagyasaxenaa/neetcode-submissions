class Solution {
public:
    void solve(int ind, string&digits, string&var, vector<string>&ret, map<int,string>&m){
        if(ind==digits.size()){
            ret.push_back(var);
            return;
        }
        for(char c: m[digits[ind]-'0']){
            var.push_back(c);
            solve(ind+1,digits,var,ret,m);
            var.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string &digits) {
        vector<string>ret;
        if(digits.size()==0){
            return ret;
        }
        map<int, string>m={
            {9,"wxyz"},
            {8,"tuv"},
            {7,"pqrs"},
            {6,"mno"},
            {5,"jkl"},
            {4,"ghi"},
            {3,"def"},
            {2,"abc"}    
        };
        string var;
        solve(0,digits,var,ret,m);
        return ret;

    }
};

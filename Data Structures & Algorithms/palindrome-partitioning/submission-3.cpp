class Solution {
public:
    bool palindrome(string& str,int start, int end) {
        while (start <= end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void part(int ind, string&s,vector<vector<string>>&ret, vector<string>&var){
        if(ind>=s.size()){
            ret.push_back(var);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(!palindrome(s,ind,i)){
                continue;
            }
            var.push_back(s.substr(ind,i-ind+1));
            part(i+1,s,ret,var);
            var.pop_back();
        } 
        return ;
    }
    vector<vector<string>> partition(string &s) {
        vector<vector<string>>ret;
        vector<string>var;
        part(0,s,ret,var);
        return ret;
    }
};

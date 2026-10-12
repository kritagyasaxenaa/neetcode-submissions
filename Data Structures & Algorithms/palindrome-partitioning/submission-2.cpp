class Solution {
public:
       bool palindrome(string& str) {
        int start=0, end=str.size()-1;
        while (start <= end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void part(int i, string&s,vector<vector<string>>&ret){
        if(i==s.size()){
            vector<string> b;
            ret.push_back(b);
            return;
        }
        vector<vector<string>>r;
        part(i+1,s,r);
        int n=r.size();
        for(int j=0;j<n;j++){
                       bool var=false;
            int m=r[j].size();
            for(int k=0;k<m-1;k++){
                if(!palindrome(r[j][k])){
                    var=true;
                    break;
                }
            }
            if(var){
                continue;
            }
            string temp;
            temp.push_back(s[i]);
            r[j].push_back(temp);
            ret.push_back(r[j]);
            r[j].pop_back();
            if(r[j].size()!=0){
                temp+=r[j].back();
                r[j].back()=temp;
                ret.push_back(r[j]);
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ret,temp;
        part(0,s,ret);
        for(int i=0;i<ret.size();i++){
            bool var=false;
            for(int j=0;j<ret[i].size();j++){
                if(!palindrome(ret[i][j])){
                    var=true;
                    break;
                }
            }
            if(var){
                continue;
            }
            temp.push_back(ret[i]);
        }
        return temp;
    }
};

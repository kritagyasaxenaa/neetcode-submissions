class Solution {
public:

    string encode(vector<string>& strs) {
        char var='\t';
        string a;
        for( string s:strs){
            a=a+var;
            a=a+s;
        }
        return a;
    }

    vector<string> decode(string s) {
        vector<string>a;
        bool temp=false;
        for(int i=0;i<s.size();){
            if(s[i]=='\t'){
                i++;
                string b;
                while(i<s.size()&&s[i]!='\t'){
                    b=b+s[i];
                    i++;
                }
                a.push_back(b);
            }
        }
        return a;
    }
};

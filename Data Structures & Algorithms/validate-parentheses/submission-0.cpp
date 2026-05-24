class Solution {
public:
    bool isValid(string s) {
        vector<char> temp;
        for(char i:s){
            if(i=='('){
                temp.push_back(i);
            }
            if(i=='{'){
                temp.push_back(i);
            }
            if(i=='['){
                temp.push_back(i);
            }
            if(i==')'){
                if(temp.empty()){
                    return false;
                }
                auto it=temp.end()-1;
                    if(*it!='('){
                        return false;
                    }
                temp.erase(it,it+1);
            }
            if(i==']'){
                if(temp.empty()){
                    return false;
                }
                auto it=temp.end()-1;
                    if(*it!='['){
                        return false;
                    }
                temp.erase(it,it+1);
            }
            if(i=='}'){
                if(temp.empty()){
                    return false;
                }
                auto it=temp.end()-1;
                    if(*it!='{'){
                        return false;
                    }
                temp.erase(it,it+1);
            }
        }
        
        return temp.empty();
    }
};
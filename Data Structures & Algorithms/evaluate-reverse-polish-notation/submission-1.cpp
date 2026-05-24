class Solution {
public:
    int Value(int a, int b, char c){
        switch (c){
        case '+': return a+b;
        case '-': return a-b;
        case '/': return a/b;
        case '*': return a*b;
        default: return 0;
        }

    }
    int evalRPN(vector<string>& tokens) {
        stack<int>val;
        vector<char>s={'+', '-', '*', '/'};
        for(string i: tokens){
            if((i.size()==1)&&(i[0]=='+'||i[0]=='-'||i[0]=='*'||i[0]=='/')){
                int a=val.top();
                val.pop();
                int b=val.top();
                val.pop();
                val.push(Value(b,a,i[0]));
            }
            else{
                if(i[0]!='-'){
                int a=i[0]-'0';
                int k=1;
                while(k!=i.size()){
                    a=a*10;
                    a=a+i[k]-'0';
                    k++;
                }
                val.push(a);
                }
                else{
                    int a=i[1]-'0';
                int k=2;
                while(k!=i.size()){
                    a=a*10;
                    a=a+i[k]-'0';
                    k++;
                }
                val.push(-a);
                }
            }
        }
        return val.top();
    }
};

static const auto fast = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ret(temp.size(),0);
        stack<int>s;
        s.push(0);
        for(int i=1;i<temp.size();i++){
            if(s.empty()==true){
                s.push(i);
            }
            else{
                while(s.empty()==false&&temp[i]>temp[s.top()]){
                    int a=s.top();
                    ret[a]=i-a;
                    s.pop();
                }
                s.push(i);
            }
        }
        return ret;

    }
};

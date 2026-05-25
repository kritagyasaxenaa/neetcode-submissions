class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ret(temp.size(),0);
        stack<pair<int, int>>s;
        s.push({temp[0],0});
        for(int i=1;i<temp.size();i++){
            if(s.empty()==true){
                s.push({temp[i],i});
            }
            else{
                while(s.empty()==false&&temp[i]>s.top().first){
                    int a=s.top().second;
                    ret[a]=i-a;
                    s.pop();
                }
                s.push({temp[i],i});
            }
        }
        return ret;

    }
};

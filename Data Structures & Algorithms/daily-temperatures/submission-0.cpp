class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ret;
        for(int i=0;i<temp.size();i++){
            for(int j=i;j<temp.size();j++){
                if(temp[j]>temp[i]){
                    ret.push_back(j-i);
                    break;
                }
                if(j==temp.size()-1){
                    ret.push_back(0);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<float, vector<pair<int, int>>>m;
        for(vector i: points){
            float a=i[0];
            float b=i[1];
            float c=pow(((a*a)+(b*b)),0.5);
            m[c].push_back({a,b});
        }
        auto it =m.begin();
        vector<vector<int>>ret;
        for(int i=0;i<k;it++){
            for(pair<int,int> a: it->second){
                if(i==k){
                    break;
                }
                vector<int>temp;
                temp.push_back(a.first);
                temp.push_back(a.second);
                ret.push_back(temp);
                i++;
            }
        }
        return ret;
    }
};

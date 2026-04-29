class Solution {
public:
    vector<int>topKFrequent(vector<int>& nums, int k) {
       map<int,int> temp;
        for(int t: nums){
                temp[t]++;
        }

        vector<int>op;
        vector<pair<int,int>>tem;
        for(auto it=temp.begin();it!=temp.end();it++){
            tem.push_back({it->first,it->second});
        }

        sort(tem.begin(),tem.end(),[]( pair<int,int>a, pair<int,int> b){return a.second>b.second;});

        for(int i=0;i<k;i++){
            op.push_back(tem[i].first);
        }
        return op;
    }
    };

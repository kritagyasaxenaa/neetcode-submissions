class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>duo;
        for(int i=0;i<speed.size();i++){
            duo.push_back({position[i],speed[i]});
        }
        sort(duo.begin(),duo.end());
       int count=0;
       float time=0;
       for(int i=speed.size()-1;i>-1;i--){
        float p=duo[i].first;
        p=(target-p)/duo[i].second;
        if(p>time){
            count++;
            time=p;
        }
       }
       return count;
    }
};

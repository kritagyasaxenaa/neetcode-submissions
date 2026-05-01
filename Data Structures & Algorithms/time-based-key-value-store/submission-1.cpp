class TimeMap {
public:
    TimeMap(){

    }
    map<pair<string,int>,stack<string>>m;
    void set(string key, string value, int timestamp) {
        pair<string,int>a={key,timestamp};
        m[a].push(value);
        return;
    }
    
    string get(string key, int timestamp) {
         pair<string,int>a={key,timestamp};
         string s;
         if(m[a].size()==0){
            int i=timestamp;
            a={key,i};
            while(i>0&&m[a].size()==0){
                i--;
                a={key,i};
            }
            if(i!=0){
                s=m[a].top();
            }
         }
         else{
            s=m[a].top();
         }
         return s;
    }
};

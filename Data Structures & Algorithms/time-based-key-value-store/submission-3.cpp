class TimeMap {
public:
    TimeMap(){

    }
    map<string,map<int, string>>m;
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
        return;
    }
    
    string get(string key, int timestamp) {
            string s;
            int i=timestamp;
            while(i>0&&m[key][i].size()==0){
                i--;
            }
            if(i!=0){
                s=m[key][i];
            }
        
         return s;
    }
};

class KthLargest {
    // trying heaps
public:
    vector<int>v;
    int k;
    void delTop(){
        if(v.empty()){
            return;
        }
        int i=0;
        v[0]=v[v.size()-1];
        v.erase(v.end()-1);
        int j=2*i+1;
        int m;
        while(j<v.size()){
            if(j+1<v.size()){
                if(v[i]<v[j]||v[i]<v[j+1])
                    m=v[j]>v[j+1]?j:(j+1);
                else{
                    break;
                }
            }
            else{
                if(v[i]<v[j])
                    m=j;
                else{
           
                    break;
                }
            }
            int temp = v[i];
            v[i]=v[m];
            v[m]=temp;
            i=m;
            j=2*i+1;
        }
    }
    KthLargest(int a, vector<int>& nums) {
        k=a;
        for(int val: nums){
            v.push_back(val);
            int i=v.size()-1;
            while(i>0&&v[i]>v[(i-1)/2]){
                int temp=v[i];
                v[i]=v[(i-1)/2];
                v[(i-1)/2]=temp;
                i=(i-1)/2;
            }
        }
    }
    int add(int val) {
     v.push_back(val);
     int i=v.size()-1;
     while(i>0&&v[i]>v[(i-1)/2]){
        int temp=v[i];
        v[i]=v[(i-1)/2];
        v[(i-1)/2]=temp;
        i=(i-1)/2;
     }
     // created the heap
    vector<int>v2(k-1);
    for(int i=0;i<k-1;i++){
        v2[i]=v[0];
        delTop();// by default the topmost element is the kth one
    }
    int ret=v[0];
    for(int j=0;j<k-1;j++){
            v.push_back(v2[j]);
            int i=v.size()-1;
            while(i>0&&v[i]>v[(i-1)/2]){
                int temp=v[i];
                v[i]=v[(i-1)/2];
                v[(i-1)/2]=temp;
                i=(i-1)/2;
            }
    }
    return ret;
    }

};

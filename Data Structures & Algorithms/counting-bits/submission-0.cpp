class Solution {
public:
    vector<int> countBits(int a) {
        vector<int>r;
        for(int i=0;i<=a;i++){
             int count=0;
             int n=i;
            while(n!=0){
                count+=n%2;
                n=n/2;
            }
            r.push_back(count);
        }
        return r;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        const int n=arr.size();
        set<vector<int>>p;
        vector<vector<int>>op;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1,k=n-1;j<k;){
                if(arr[j]+arr[k]+arr[i]==0){
                    vector<int>a={arr[i],arr[j],arr[k]};
                    p.insert(a);
                    k--;
                }
                else if(arr[j]+arr[k]+arr[i]>0){
                    k--;
                }
                else if(arr[j]+arr[k]+arr[i]<0){
                    j++;
                }
                      
            }
        }
        for(vector<int> i:p){
            op.push_back(i);
        }
        return op;
    }
};
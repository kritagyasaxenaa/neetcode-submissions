class Solution {
public:
   int trap(vector<int>& height) {
        // first let's try brute
        // idea: to find dip, then to find increase
        int n=height.size();
        int water=0;
        int area=0;
       vector<int>left;
       vector<int>right;
       int max=height[0];
       left.push_back(max);
       for(int i=1;i<n;i++){
        if(max<height[i]){
            max=height[i];
        }
        left.push_back(max);
       }
       max=height[n-1];
       right.push_back(max);
       for(int i=n-1;i>-1;i--){
        if(max<height[i]){
            max=height[i];
        }
        right.push_back(max);
       }
       reverse(right.begin(),right.end());
       for(int i=0;i<n;i++){
        water=water+min(left[i],right[i])-height[i];
       }
        return water;
    }
};

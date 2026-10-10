class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int>a(n,0), b(n,0);
        // a stores max with 1st, b stores max without 1st
        vector<bool> flag(n,true);// is true if a[i-1] has 1st element
        a[0]=nums[0];
        a[1]=max(nums[0],nums[1]);
        b[1]=nums[1];
        flag[1]=(a[0]==a[1]);
        for(int i=2;i<n;i++){
            if(a[i-1]>nums[i]+a[i-2]){
                a[i]=a[i-1];//flag is the same
                flag[i]=flag[i-1];
            }
            else{
                a[i]=a[i-2]+nums[i];
                flag[i]=flag[i-2];
            }
            if(flag[i]){
                b[i]=max(b[i-1], b[i-2]+nums[i]);
            }
            else{
                b[i]=a[i];
            }
        }
        return max(b.back(),a[n-2]);
    }
};

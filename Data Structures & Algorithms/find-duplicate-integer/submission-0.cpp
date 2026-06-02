class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int pos=0,val=0;
        for(int i =0; i<2*n;i++){
            pos=val;
            if(nums[pos]==-1){
                return pos;
            }
            val=nums[pos];
            nums[pos]=-1;
        }
        return -1;
    }
};
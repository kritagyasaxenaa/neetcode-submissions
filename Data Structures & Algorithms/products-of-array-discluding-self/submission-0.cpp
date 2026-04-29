class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        int product=1;
        for(int i:nums){
            if(i==0){
                count++;
            }
            else{
                product=product*i;
            }
        }
        vector<int>op;
        if(count>1){
            for(int i=0;i<nums.size();i++){
                op.push_back(0);
            }
            return op;
        }
        if(count==1){
             for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    op.push_back(product);
                }
                else{
                    op.push_back(0);
                }
            }
            return op;
        }
         for(int i=0;i<nums.size();i++){
                op.push_back(product/nums[i]);
        }
        return op;
    }
};

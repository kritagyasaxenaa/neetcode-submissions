class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a=0,b=1;
        while(a!=nums.size()-1){
            b=a+1;
            while(b!=nums.size()){
                if(nums[a]+nums[b]==target){
                     vector<int>op;
                        op.push_back(a);
                        op.push_back(b);
                        return op;
                    }
                    b++;
            }
            a++;
        }
      vector<int>op;
      return op;
       
    }
};

class Solution {
public:
    vector<vector<int>>ret;
    void combSum(vector<int>&nums, int target, int i, int sum, vector<int>&var){
        if(i==nums.size()){
            return;
        }
        combSum(nums,target,i+1,sum,var);//not including
        sum+=nums[i];
        if(sum<=target){
            var.push_back(nums[i]);
            if(sum==target){
                ret.push_back(var);
            }
            if(sum<target){
                combSum(nums,target,i,sum,var);
            }
            var.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>var;
        combSum(nums,target,0,0,var);
        return ret;    
    }
};

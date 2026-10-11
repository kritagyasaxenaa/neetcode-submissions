class Solution {
public:
    
    void combSum(vector<int>&nums, int target, int i, int sum, vector<int>&var,vector<vector<int>>&ret){
        if(i==nums.size()){
            return;
        }
        combSum(nums,target,i+1,sum,var,ret);//not including
        sum+=nums[i];
        if(sum<=target){
            var.push_back(nums[i]);
            if(sum==target){
                ret.push_back(var);
            }
            if(sum<target){
                combSum(nums,target,i,sum,var,ret);
            }
            var.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>var;
        vector<vector<int>>ret;
        combSum(nums,target,0,0,var,ret);
        return ret;    
    }
};

class Solution {
public:
    void combSum(vector<int>&nums, int target, int i, int sum,  vector<int>&var, vector<vector<int>>&ret){
        if(i>=nums.size()){
            return;
        }
        sum+=nums[i];
        var.push_back(nums[i]);
            if(sum==target){
                ret.push_back(var);
            }
            if(sum<target){
                combSum(nums,target,i+1,sum,var,ret);
            }
        var.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        sum-=nums[i];
        combSum(nums,target,i+1,sum,var,ret);//not including
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
       vector<int>var;
        vector<vector<int>>ret;
        combSum(candidates,target,0,0,var,ret);
        return ret;    
    }
};

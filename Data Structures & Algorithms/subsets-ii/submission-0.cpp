class Solution {
public:
    void subs(int i, vector<int>&nums, vector<int>&var, vector<vector<int>>&ret){
        if(i>=nums.size()){
            return;
        }
        // case 1: include the number
        var.push_back(nums[i]);
        ret.push_back(var);
        subs(i+1,nums,var,ret);
        var.pop_back();
        //skip all duplicates for not inclusion, because they'll produce redundant sets
        while(i+1<nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        subs(i+1,nums,var,ret);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>var;
        vector<vector<int>>ret;
        ret.push_back(var);
        subs(0,nums,var,ret);
        return ret;
    }
};

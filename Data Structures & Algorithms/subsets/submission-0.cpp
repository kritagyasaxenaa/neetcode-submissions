class Solution {
public:
    vector<vector<int>>ret;
    void subs(vector<int>&nums, int index, vector<int>var){
        if(index==nums.size()){
            return;
        }
        subs(nums,index+1,var);// not including
        var.push_back(nums[index]);
        ret.push_back(var);
        subs(nums,index+1,var);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back({});
        subs(nums,0,{});
        return ret;
    }
};

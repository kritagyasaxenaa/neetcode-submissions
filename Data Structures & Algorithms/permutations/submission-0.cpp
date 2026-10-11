class Solution {
public:
    void order(int i, vector<int>&nums,vector<int>&var,vector<vector<int>>&ret){
        // basic idea
        while(i<nums.size()&&nums[i]<-10){
            i++;
        }
        if(i>=nums.size()){
            return;
        }
        // a valid number, part of the subarray
        var.push_back(nums[i]);
        nums[i]-=100;
        if(var.size()==nums.size()){
            ret.push_back(var);
            nums[i]+=100;
            var.pop_back();
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]<-10){
                continue;
            }
            order(j,nums,var,ret);
        }
        nums[i]+=100;
        var.pop_back();
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
     // make already included ones as -1   
     vector<int>var;
     vector<vector<int>>ret;
        for(int j=0;j<nums.size();j++){
            order(j,nums,var,ret);
        }
     return ret;
    }
};

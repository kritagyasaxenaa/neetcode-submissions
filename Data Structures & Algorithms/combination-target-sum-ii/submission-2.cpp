class Solution {
public:
    void combSum(vector<int>&nums, int target, int i, int sum,  vector<int>&var, vector<vector<int>>&ret, map<int,int>&freq){
        if(i==nums.size()){
            return;
        }
        vector<int>temp=var;
        combSum(nums,target,i+1,sum,var,ret,freq);//not including
        for(int j=0;j<freq[nums[i]];j++){// can include upto n times where n is the frequency of the number
            sum+=nums[i];
            if(sum<=target){
                var.push_back(nums[i]);
                if(sum==target){
                    if(find(ret.begin(),ret.end(),var)==ret.end())
                        ret.push_back(var);
                }
                if(sum<target){
                    combSum(nums,target,i+1,sum,var,ret,freq);
                }
            }
        }
        var=temp;
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
     vector<int>nums;
     map<int,int>freq;   
     nums.push_back(candidates[0]);
     freq[candidates[0]]++;
     for(int i=1;i<candidates.size();i++){
        freq[candidates[i]]++;
        if(candidates[i]!=candidates[i-1]){
            nums.push_back(candidates[i]);
        }
     }
       vector<int>var;
        vector<vector<int>>ret;
        combSum(nums,target,0,0,var,ret,freq);
        return ret;    
    }
};

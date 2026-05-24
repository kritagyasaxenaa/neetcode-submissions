class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max=nums[0];
        for(int i=0;i<k;i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        vector<int>ret;
        int start=0, end =k-1;
        ret.push_back(max);
        for(int i=k;i<nums.size();i++){
            end++;
            if(max==nums[start]){
                max=nums[i];
                for(int j=start+1;j<=end;j++){
                    if(max<nums[j]){
                        max=nums[j];
                    }
                }
                ret.push_back(max);
            }
            else{
                if(max<nums[i]){
                    max=nums[i];
                }
                ret.push_back(max);
            }
            start++;
        }
        return ret;
    }
};

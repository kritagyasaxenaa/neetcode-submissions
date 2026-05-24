class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max=nums[0];
        map<int,int>s;
        for(int i=0;i<k;i++){
            if(max<nums[i]){
                max=nums[i];
            }
            s[nums[i]]++;
        }
        vector<int>ret;
        int start=0, end=k-1;
        ret.push_back(max);
        for(int i=k;i<nums.size();i++){
            s[nums[start]]--;
            if(s[nums[start]]==0){
                s.erase(nums[start]);
            }
            s[nums[i]]++;
            end++;
            if(max==nums[start]){
                max=prev(s.end())->first;
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

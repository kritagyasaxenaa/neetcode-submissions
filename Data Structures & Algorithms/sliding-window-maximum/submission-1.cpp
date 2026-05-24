class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start=0;
        int end=k-1;
        int max=nums[0];
        queue<int>q;
        for(int i=0;i<k;i++){
            if(max<nums[i]){
                max=nums[i];
            }
            q.push(nums[i]);
        }
        vector<int>ret;
        ret.push_back(max);
        for(int i=k;i<nums.size();i++){
            q.push(nums[i]);
            if(max==q.front()){
                q.pop();
                max=q.front();
                queue <int> q2 = q ;
                while(q2.empty()==false){
                    int j=q2.front();
                    if(max<j){
                        max=j;
                    }
                    q2.pop();
                }
                ret.push_back(max);
            }
            else{
                if(max<nums[i]){
                    max=nums[i];
                }
                q.pop();
                ret.push_back(max);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=nums[0];
        int n=nums.size();
        if(nums[n-1]>nums[0]){
            return nums[0];
        }
        // we need to find the pivot range 1 to n-1
        int low=1, high=n-1;
        while(high>=low){
            int mid =low+(high-low)/2;
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            //how do we decide which half?
            //check which half is sorted and remove it 
            else if(nums[mid]<nums[high]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return min;
    }
};
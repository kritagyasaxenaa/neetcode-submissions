class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double val;
        for(int i: nums2){
            nums1.push_back(i);
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size()%2!=0){
            val=nums1[nums1.size()/2];
            return val;
        }
        val=nums1[nums1.size()/2]+nums1[nums1.size()/2-1];
        val=val/2;
        return val;
    }
};
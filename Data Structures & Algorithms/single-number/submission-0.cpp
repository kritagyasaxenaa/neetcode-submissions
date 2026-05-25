class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //set or map in O(n)
        //sum can't be used
        // xor 
        int a=0;
        for(int i: nums){
            a=a^i;
        }
        return a;
    }
};

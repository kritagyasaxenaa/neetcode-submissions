class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end=height.size()-1;
        int amount=0;
        int max=0;
        while(end!=start){
            amount=min(height[start],height[end])*(end-start);
            if(amount>max){
                max=amount;
            }
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }

        }
        return max;
    }
};
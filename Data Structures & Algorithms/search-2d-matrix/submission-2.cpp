class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n = matrix[0].size();
        int i = 0;
        for(;i<m;i++){
            if(target>matrix[i][n-1]){
                continue;
            }
            if(target<matrix[i][0]){
                return false;
            }
            else{
                break;
            }
        }
        if(i>=m){
            return false;
        }
        int left=0, right=n-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};

class Solution {
public:
void graph(vector<vector<int>>&grid, int i, int j, int& var){
        if(i>=grid.size()||i<0){
            return;
        }
        if(j>=grid[0].size()||j<0){
            return;
        }
        if(grid[i][j]!=1){
            return;
        }
        var++;
        grid[i][j]=0;
        graph(grid,i+1,j,var);
        graph(grid,i-1,j,var);
        graph(grid,i,j+1,var);
        graph(grid,i,j-1,var);
        
        return;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int var=0;
                    graph(grid,i,j,var);
                   ret=max(ret,var);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
void graph(vector<vector<int>>&grid, int i, int j, int var){
        if(i>=grid.size()||i<0){
            return;
        }
        if(j>=grid[0].size()||j<0){
            return;
        }
         if(grid[i][j]==3){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        else if(grid[i][j]==1){
            var++;
            grid[i][j]=-var;
        }
        else if(grid[i][j]==2){
            grid[i][j]=3;
        }
        else if(grid[i][j]>-var-1){
            return;
        }
        else{
            var++;
            grid[i][j]=-var;
        }
        graph(grid,i+1,j,var);
        graph(grid,i-1,j,var);
        graph(grid,i,j+1,var);
        graph(grid,i,j-1,var);
        if(grid[i][j]==3){
            grid[i][j]=2;
        }
        return;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        // multiple graphs, connected components
         int ret=INT_MAX;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    graph(grid,i,j,0);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
                else{
                    ret=min(ret,grid[i][j]);
                }
            }
        }
        if(ret>0){
            return 0;
        }
        ret=-ret;
        return ret;
    }
};

class Solution {
public:
    void graph(vector<vector<char>>&grid, int i, int j){
        if(i>=grid.size()||i<0){
            return;
        }
        if(j>=grid[0].size()||j<0){
            return;
        }
        if(grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        graph(grid,i+1,j);
        graph(grid,i-1,j);
        graph(grid,i,j+1);
        graph(grid,i,j-1);
        
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        // graph mein bfs
        int ret=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                   graph(grid,i,j);
                    ret++;
                }
            }
        }
        return ret;
    }
};

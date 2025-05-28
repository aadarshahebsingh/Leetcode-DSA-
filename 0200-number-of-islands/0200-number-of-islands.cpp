class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=n || j>=m)return;
        if(i<0 || j<0)return;

        if(grid[i][j]!='1')return;
        grid[i][j]='x';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
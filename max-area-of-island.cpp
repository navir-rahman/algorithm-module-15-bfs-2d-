class Solution {
public:
    int n,m;
    vector<pair<int,int>> path={{-1,0},{1,0}, {0,-1}, {0,1}};
    bool vis[100][100];
    bool isvalid(int ci, int cj)
    {
            if(ci >= 0&& ci <n &&cj >= 0 && cj<m) return true;
            else return false;
    }



    void dfs(int si, int sj, vector<vector<int>>& grid){
        vis[si][sj]=true;
        for(int i=0; i<4; i++){
            pair<int,int> p=path[i];
            int ci = si+ p.first;
            int cj = cj +p.second;
            if(isvalid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1)
            {
            dfs(ci,cj, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i,j,grid);
                }
            }
        }

    }
};
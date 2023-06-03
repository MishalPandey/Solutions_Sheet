//Solution 1 , T.C{O(n*m)}, S.C{O(n*m)} 


class Solution {
public:

    void combine_islands(vector<vector<char>>& grid, int n, int m,  int i, int j, vector<vector<bool>>&vis)
    {
        vis[i][j]= true;

        if(i+1<n && !vis[i+1][j] && grid[i+1][j]=='1')
        {
            combine_islands(grid, n, m, i+1, j, vis);
        }
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]=='1')
        {
            combine_islands(grid, n, m, i-1, j, vis);
        }
        if(j+1<m && !vis[i][j+1] && grid[i][j+1]=='1')
        {
            combine_islands(grid, n, m, i, j+1, vis);
        }
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]=='1')
        {
            combine_islands(grid, n, m, i, j-1, vis);
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, 0));

        int ans=0;

        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    combine_islands(grid, n, m, i, j, vis);

                }


            }
        }

        return ans;
        
    }
};

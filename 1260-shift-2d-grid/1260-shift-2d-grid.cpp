class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
         k = k % (m*n);
        if(k == 0) return grid;
        if(m == 1 && n == 1) return grid;
        vector<vector<int>>ans(m , vector<int>(n,0));
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j <m ; j++)
        //     {
        //         ans[i][j] = grid[i][j+1];
        //     }
        // }
        int i = 0 , j = 0;
        for(int x = 1; x <= k ; x++ )
        {
            
            while(i<m && j < n)
            {
                if( i == m -1 && j == n - 1)
                {
                    ans[0][0] = grid[i][j];
                    // return ans;
                    break;
                }
                if(j == n - 1)
                {
                    ans[i+1][0] = grid[i][j];
                    j  = 0;
                    i++;
                }
                else
                {
                    ans[i][j+1] = grid[i][j];
                    j++;
                }
            }
        grid = ans;
        // k--;
        i = 0 , j =0;
        }
        return ans;
    }
};
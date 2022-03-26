class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(grid, 0,0, m, n,dp);
        
    }
    
    int solve(vector<vector<int>>& grid, int curR, int curC, int m, int n,vector<vector<int>>& dp)
    {
        if(curR>=m || curC>=n || grid[curR][curC]==1)
        {
            return 0;
        }
        if(curR==m-1 && curC==n-1)
        {
            return 1;
        }
        
        if(dp[curR][curC]!=-1)
        {
            return dp[curR][curC];
        }
        int right=solve(grid, curR, curC+1, m, n,dp);
        int down=solve(grid, curR+1, curC, m ,n,dp);
        
        return dp[curR][curC]=right+down;
    }
};
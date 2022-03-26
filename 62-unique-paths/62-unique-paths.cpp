class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
    int solve( int curRow, int curCol, int m, int n, vector<vector<int>>&dp)
    {
      
        
        if(curRow>=m || curCol>=n)
        {
            return 0;
        }
          if(curRow==m-1 && curCol==n-1)
        {
            return 1;
        }
        if(dp[curRow][curCol]!=-1)
        {
           return  dp[curRow][curCol];
        }
        //int ans=0;
        int right=solve(curRow, curCol+1, m, n,dp);
        int down=solve(curRow+1, curCol, m,n,dp);
        
        return dp[curRow][curCol]= right+down;
    }
};
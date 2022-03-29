class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(dungeon, 0,0,m,n,dp);
    }
    
    int solve(vector<vector<int>>&mat, int i, int j, int m, int n,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
        {
            return 100001;
        }
        
        if(i==m-1 && j==n-1)
        {
            return mat[i][j]<=0 ? 1-mat[i][j] : 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int right=solve(mat,i,j+1,m,n,dp);
        int down= solve(mat,i+1,j,m,n,dp);
        
        int curVal=mat[i][j];
        int nextVal=min(right,down);
        
        if(curVal>=nextVal)
        {
            return dp[i][j] =1;
        }
        
        return dp[i][j]= nextVal-curVal;
    }
};
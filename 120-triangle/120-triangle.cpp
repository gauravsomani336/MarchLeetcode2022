class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1,-1));
        return solve(triangle,0,0,m,m,dp);
        
        
    }
    int solve(vector<vector<int>>&mat, int i, int j, int m, int n,vector<vector<int>>&dp)
    {
        if(i==m-1)
        {
            return mat[i][j];
        }
        
        if(i>=m || j>=n)
        {
            return 1000001;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        
       int left=mat[i][j]+ solve(mat, i+1, j,m,n,dp);
    int right= mat[i][j] + solve(mat, i+1, j+1, m,n,dp);
        
        ans=min(left,right);
        return dp[i][j]= ans;
    }
};
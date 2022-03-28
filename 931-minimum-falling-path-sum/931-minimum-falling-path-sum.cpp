class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MAX;
        unordered_map<string,int>dp;
        for(int j=0;j<n;j++)
        {
            int tmp=solve(matrix,0,j,m,n,dp);
            ans=min(tmp,ans);
            
        }
        return ans;
    }
    
    int solve(vector<vector<int>>&mat , int curR, int curC, int m ,int n, unordered_map<string,int>&dp)
    {
        if(curC<=-1 || curC>=n)
        {
            return 100001;
        }
        
        if(curR==m-1 )
        {
            return mat[curR][curC];
        }
        string curkey=to_string(curR)+"-"+to_string(curC);
        if(dp.find(curkey)!=dp.end())
        {
            return dp[curkey];
        }
            
        int down=mat[curR][curC] + solve(mat, curR+1, curC, m,n,dp);
        int downLeft= mat[curR][curC] + solve(mat, curR+1, curC-1,m ,n,dp);
        int downRight = mat[curR][curC] + solve(mat, curR+1, curC+1, m , n,dp) ;
        
        int tmp=min(down, min(downLeft, downRight));
        return dp[curkey]=tmp;
    }
};
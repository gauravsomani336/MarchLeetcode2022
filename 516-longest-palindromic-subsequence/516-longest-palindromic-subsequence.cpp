class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.length();
        string k(s);
        reverse(k.begin(), k.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(s,k, 0,0,m,m,dp);
    }
    
    int solve(string &s1, string &s2, int i, int j, int m, int n , vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int mx=0;
        if(s1[i]==s2[j])
        {
            mx=1+ solve(s1, s2, i+1, j+1, m ,n,dp);
            
        }
        else
        {
            mx= max(solve(s1,s2,i+1,j,m,n,dp), solve(s1,s2,i,j+1,m,n,dp));
        }
        
        return dp[i][j]=mx;
    }
};
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,0,n,dp);
    }
    
    int solve(string &s, int i, int n,vector<int>&dp)
    {
        if(i>=n)
        {
            return 1;
        }
        
        if(s[i]=='0')
        {
            return 0;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int ways=0;
        
        ways+= solve(s,i+1,n,dp);
        
        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
        {
            ways+= solve(s, i+2, n,dp);
        }
        
        return dp[i]=ways;
    }
};
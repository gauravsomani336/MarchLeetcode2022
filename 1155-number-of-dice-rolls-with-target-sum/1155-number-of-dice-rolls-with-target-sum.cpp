#define MOD 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1, -1));
        return solve(n,k,target,dp);
    }
    
    int solve(int n, int f, int target, vector<vector<int>>&dp)
    {
        if(n==0 && target==0)
        {
            return 1;
        }
        
        if(n==0 || target<=0)
        {
            return 0;
        }
        
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        
        int ways=0;
        for(int i=1;i<=f;i++)
        {
            int tmp=solve(n-1,f,target-i,dp) % MOD;
            ways= ways %MOD;
            ways=(tmp+ways) %MOD;
        }
        
        return dp[n][target]=ways;
    }
};
class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(1,n,0,dp) ;
    }
    int solve(int cur, int amount,int k, vector<vector<int>>&dp)
    {
        // if(amount<0)
        // {
        //     return 0;
        // }
        if(amount==0)
        {
            return k>=2?1:0;
        }
        if(cur>amount)
        {
            return 0;
        }
        
        if(dp[cur][amount]!=-1)
        {
            return dp[cur][amount];
        }
        
        int consider=0;
        
        if(cur <= amount)
        {
            consider=cur* solve(cur,amount-cur,k+1,dp);
        }
        int notConsider=solve(cur+1,amount,k,dp);
        
        return dp[cur][amount]= max(consider,notConsider);
    }
};
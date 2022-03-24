class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return solve(prices, 0,1, dp);
    }
    int solve(vector<int>&prices, int cur, int canBuy,  vector<vector<int>>&dp)
    {
        if(cur>=prices.size())
        {
            return 0;
        }
        
        if(dp[cur][canBuy]!=-1)
        {
            return dp[cur][canBuy];
        }
        int mx=0;
        if(canBuy==1)
        {
            int idle=solve(prices, cur+1, canBuy, dp);
            int buy= -prices[cur]+ solve(prices, cur+1, 0, dp);
            mx=max(idle, buy);
        }
        else
        {
            int idle=solve(prices, cur+1, canBuy, dp);
            int sell= prices[cur]+ solve(prices, cur+2, 1, dp);
            mx=max(idle, sell);
        }
        return dp[cur][canBuy]=mx;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1 ,dp,fee);
        
    }
    int solve (vector<int>&prices, int cur, int canBuy, vector<vector<int>>&dp, int fee)
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
            int idle=solve(prices, cur+1, canBuy, dp, fee);
            int buy= -prices[cur]+ solve(prices, cur+1, 0, dp, fee);
            mx=max(idle,buy);
        }
        else
        {
            int idle=solve(prices, cur+1, canBuy, dp, fee);
            int sell= -fee + prices[cur] + solve(prices, cur+1, 1, dp, fee);
            mx=max(idle,sell);
        }
        
        return dp[cur][canBuy]=mx;
    }
};
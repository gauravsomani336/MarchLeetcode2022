class Solution {
public:
    // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(2,-1)));

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,1,dp);
    }
    int solve(vector<int>&prices,int cur, int canBuy, int transCount,  vector<vector<vector<int>>>&dp)
    {
        if(cur>=prices.size() || transCount==0)
        {
            return 0;
        }
        
     if(dp[cur][canBuy][transCount]!=-1)
     {
         return dp[cur][canBuy][transCount];
     }
        int mx=0;
        if(canBuy==1)
        {
            int idle= solve(prices, cur+1, canBuy, transCount,dp );
            int buy= -prices[cur] + solve(prices, cur+1, 0, transCount,dp);
            mx=max(idle,buy);
        }
        else
        {
            int idle=solve(prices, cur+1, canBuy, transCount,dp);
            int sell= prices[cur]+ solve(prices, cur+1, 1, transCount-1,dp );
            mx=max(idle,sell);
        }
        return dp[cur][canBuy][transCount]=mx;
    }
};



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<string,int>mp;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,mp,dp);
        
    }
    int solve(int cur, int amount, vector<int>&coins, unordered_map<string,int>&mp,vector<vector<int>>&dp )
    {
        if(amount==0)
        {
            return 1;
        }
        
        if(cur==coins.size())
        {
            return 0;
        }
        
//         string curkey=to_string(cur)+"-"+to_string(amount);
        
//         if(mp.find(curkey)!=mp.end())
//         {
//             return mp[curkey];
//         }
        
        if(dp[cur][amount]!=-1)
        {
            return dp[cur][amount];
        }
        int consider=0;
        if(coins[cur]<=amount)
        {
            consider=solve(cur,amount-coins[cur], coins, mp,dp);
        }
        
        int notconsider=solve(cur+1, amount, coins, mp,dp);
        
        // return mp[curkey]=consider+notconsider;
        return dp[cur][amount]=consider+notconsider;
    }
};
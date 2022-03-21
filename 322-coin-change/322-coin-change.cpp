class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<string,int>mp;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,mp,dp);
        return ans==1e9?-1:ans;
    }
    int solve(int cur,int amount, vector<int>&coins,unordered_map<string,int>&mp, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(cur==coins.size() && amount!=0)
        {
            return 1e9;
        }
        // string curkey=to_string(cur)+"-"+to_string(amount);
        // if(mp.find(curkey)!=mp.end())
        // {
        //     return mp[curkey];
        // }
        
        if(dp[cur][amount]!=-1)
        {
            return dp[cur][amount];
        }
        
        int consider=INT_MAX;
        if(coins[cur]<=amount)
        {
            consider=1+solve(cur,amount-coins[cur],coins,mp,dp);
        }
        int notConsider=solve(cur+1, amount, coins,mp,dp);
        
        // return  mp[curkey]= min(consider, notConsider);
        return dp[cur][amount]=min(consider, notConsider);
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        int zero =solve(0,cost,mp);
        int one= solve(1,cost,mp);
        return min(one,zero);
    }
    int solve(int cur, vector<int>&cost, unordered_map<int,int>&mp)
    {
        if(cur==cost.size())
        {
            return 0;
        }
        if(cur>cost.size())
        {
            return 1001;
        }
        
        int curkey=cur;
        if(mp.find(curkey)!=mp.end())
        {
            return mp[curkey];
        }
        
        int one=cost[cur]+solve(cur+1, cost, mp);
        int two=cost[cur]+solve(cur+2, cost, mp);
        
        return mp[curkey]=min(one,two);
        
    }
};
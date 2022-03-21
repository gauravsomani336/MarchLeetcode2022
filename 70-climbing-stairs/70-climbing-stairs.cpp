class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return solve(0,n, mp);
    }
    int solve(int cur,int target, unordered_map<int,int>&mp)
    {
        if(cur==target)
        {
            return 1;
        }
        if(cur>target)
        {
            return 0;
        }
        
        int curkey=cur;
        if(mp.find(curkey)!=mp.end())
        {
            return mp[curkey];
        }
        int one =solve(cur+2,target,mp);
        int two= solve(cur+1, target, mp);
        
        return mp[curkey]=one+two;
    }
};
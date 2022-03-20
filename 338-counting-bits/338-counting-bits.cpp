class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        unordered_map<int,int>mp;
        for(int i=0;i<=n;i++)
        {
            ans[i]= solve(i,mp);
        }
        return ans;
    }
    int solve(int n,unordered_map<int,int>&mp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        int curkey=n;
        if(mp.find(curkey) != mp.end())
        {
            return mp[curkey];
        }
        
        if(n%2 == 0)
        {
            mp[curkey]=solve(n/2,mp);
            return solve(n/2,mp);
        }
        else
        {
            mp[curkey]=1+solve(n/2,mp);
            return 1+solve(n/2,mp);
        }
    }
};
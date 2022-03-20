class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(100001,0);
        int mx=INT_MIN;
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            freq[it]+=1;
            mx=max(mx,it);
        }
        
        return solve(freq,0,mx,mp);
        
    }
    int solve(vector<int>&freq,  int cur, int mx,unordered_map<int,int>&mp)
    {
        if(cur>mx)
        {
            return 0;
        }
        
        int curkey=cur;
        if(mp.find(curkey)!=mp.end())
        {
            return mp[curkey];
        }
        int consider=cur*freq[cur]+solve(freq,cur+2,mx,mp);
        int notconsider=solve(freq,cur+1,mx,mp);
        mp[curkey]=max(consider,notconsider);
        return max(consider,notconsider);
    }
};
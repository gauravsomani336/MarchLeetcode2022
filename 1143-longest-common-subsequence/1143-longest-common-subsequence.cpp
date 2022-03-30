class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // unordered_map<string,int>mp;
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>mp(m+1,vector<int>(n+1,-1));
        return solve(text1, text2, 0,0, text1.length(), text2.length(), mp);
        
    }
    
    int solve(string &s1, string &s2, int i, int j, int m, int n, vector<vector<int>>&mp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        string curkey=to_string(i)+"-"+to_string(j);
        
        // if(mp.find(curkey)!=mp.end())
        // {
        //     return mp[curkey];
        // }
        if(mp[i][j]!=-1)
        {
            return mp[i][j];
        }
        
        
        int mx=0;
        if(s1[i]==s2[j])
        {
            mx=1+ solve(s1,s2,i+1,j+1,m,n,mp);
        }
        else
        {
            mx=max(solve(s1,s2,i+1,j,m,n,mp), solve(s1,s2,i,j+1,m,n,mp));
        }
        
        return mp[i][j]=mx;
    }
};
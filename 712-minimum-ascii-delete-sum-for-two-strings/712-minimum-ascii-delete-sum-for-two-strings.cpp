class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length();
        int n= s2.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(s1, s2, 0, 0, m, n, dp);
    }
    
    int solve(string &s1, string &s2, int i, int j, int m,int n,  vector<vector<int>>&dp)
    {
        if(j>=n)
        {
            int count =0;
            for(int x=i;x<m;x++)
            {
                count+=int(s1[x]);
            }
            return count;
        }
        
        if(i>=m)
        {
            int count =0;
            for(int x=j;x<n;x++)
            {
                count+=int(s2[x]);
            }
            return count;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ways=0;
        
        if(s1[i]==s2[j])
        {
            ways= solve(s1, s2, i+1, j+1, m,n, dp);
        }
        else
        {
            int left=int(s1[i]) + solve(s1, s2, i+1, j, m,n, dp);
            int right= int(s2[j]) + solve(s1, s2, i, j+1, m,n, dp);
            
            ways=min(left, right);
        }
        
        return  dp[i][j]= ways;
    }
};
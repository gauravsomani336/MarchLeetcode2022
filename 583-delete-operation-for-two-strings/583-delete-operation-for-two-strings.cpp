class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n= word2.length();
        
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(word1, word2, 0,0,m,n, dp);
    }
    
    int solve(string &s1, string &s2, int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        if(j>=n)
        {
            return m-i;
        }
        
        if(i>=m)
        {
            return n-j;
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
            int left= 1+ solve(s1, s2, i+1, j, m, n, dp);
            int right = 1+ solve(s1, s2, i, j+1, m, n , dp);
            
            ways= min(left, right);
        }
        
        return dp[i][j]= ways;
    }
};
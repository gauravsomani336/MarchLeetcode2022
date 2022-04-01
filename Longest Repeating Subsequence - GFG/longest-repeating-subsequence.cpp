// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int m=str.length();
		    vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
		    return solve(str, 0,0,m, dp);
		}
		
		int solve(string &s, int i, int j, int m, vector<vector<int>>&dp)
		{
		    if(i>=m || j>=m)
		    {
		        return 0;
		    }
		    
		    if(dp[i][j]!=-1)
		    {
		        return dp[i][j];
		    }
		    
		    int ways=0;
		    
		    if(s[i]==s[j]  && i!=j)
		    {
		        ways= 1+ solve(s, i+1, j+1, m, dp);
		    }
		    else
		    {
		        ways= max(solve(s,i+1,j,m, dp), solve(s,i,j+1, m, dp));
		    }
		    
		    return dp[i][j]=ways;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
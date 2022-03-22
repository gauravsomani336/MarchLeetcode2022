// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,price,dp);
    }
    int solve(int cur, int n, int price[], vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(cur>=n)
        {
            return 0;
        }
        if(dp[cur][n]!=-1)
        {
            return dp[cur][n];
        }
        int len=cur+1;
        int consider=0;
        if(len<=n)
        {
            consider=price[cur]+solve(cur,n-len,price,dp);
            
        }
        int notConsider=solve(cur+1,n,price,dp);
        
        return dp[cur][n]=max(consider, notConsider);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
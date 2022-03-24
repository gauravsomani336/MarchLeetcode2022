// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
//#define  ll long long
ll solve(vector<int>&sizes, ll  cur, ll  n, vector<ll>dp)
{
    if(n==0)
    {
        return 1;
    }
    if(cur>=sizes.size())
    {
        return 0;
    }
    if(dp[cur]!=-1)
    {
        return dp[cur];
    } 
    
    ll consider=0;
    if(sizes[cur]<=n)
    {
        consider=solve(sizes, cur, n-sizes[cur],dp);
    }
    ll notConsider=solve(sizes, cur+1, n,dp);
    
    return dp[cur]=consider+notConsider;
}
long long int count(long long int n)
{
      vector<ll>dp(n+1,-1);
//	table[0]=1;                 // If 0 sum is required number of ways is 1.
	vector<int>sizes={3,5,10};
	return solve(sizes,0,n,dp);
	
	
//	return table[n];
}


// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
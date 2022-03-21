// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        unordered_map<string,int>mp;
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N, W, 0, val, wt, mp,dp);
    }
    int solve(int N, int capacity, int cur, int val[], int wt[], unordered_map<string,int>&mp ,vector<vector<int>>&dp)
    {
        if(capacity==0)
        {
            return 0;
        }
        if(cur==N)
        {
            return 0;
        }
        
        string curkey=to_string(cur)+"-"+to_string(capacity);
        // if(mp.find(curkey)!=mp.end())
        // {
        //     return mp[curkey];
        // }
        
        if(dp[cur][capacity]!=-1)
        {
            return dp[cur][capacity];
        }
        
        int consider=0;
        if(wt[cur]<=capacity)
        {
            consider=val[cur]+solve(N,capacity-wt[cur],cur,val,wt,mp,dp);
        }
        int notconsider=solve(N,capacity,cur+1,val,wt,mp,dp);
        
        // return mp[curkey]=max(consider,notconsider);
        return dp[cur][capacity]=max(consider,notconsider);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
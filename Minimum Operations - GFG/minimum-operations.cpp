// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        return solve(n);
    }
    int solve( int num)
    {
        if(num==1 || num==0)
        {
            return num;
        }
        int ans=0;
      if(num%2==0)
      {
          ans=1+solve(num/2);
      }
      else
      {
          ans=1+solve(num-1);
      }
      return ans;
    
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends
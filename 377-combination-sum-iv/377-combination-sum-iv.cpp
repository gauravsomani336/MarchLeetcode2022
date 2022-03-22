class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ans=0;
        unordered_map<int,int>mp;
      return solve(0,target,nums,mp);
       // return ans;
    }
  int solve(int cur,long int target, vector<int>&nums, unordered_map<int,int>&mp)
    {
      //   if(target==0)
      //   {
      //       ans+=1;
      //       return;
      //   }
      // // if(cur==nums.size() && target>0)
      // // {
      // //     return;
      // // }
      // if(cur>=nums.size())
      // {
      //     return ;
      // }
      // if(nums[cur]<=target)
      // {
      //     solve(cur,target-nums[cur],nums,ans);
      // }
      // solve(cur+1,target,nums,ans);
      // return;
      
      if(target==0)
      {
          return 1;
      }
      if(cur>=nums.size())
      {
          return 0;
      }
      int curkey=target;
      if(mp.find(curkey)!=mp.end())
      {
          return mp[curkey];
      }
      int ans=0;
     // int ans1=0;
      if(nums[cur]<=target)
      {
          ans+= solve(0,target-nums[cur], nums,mp);
      }
      ans+=solve(cur+1,target,nums,mp);
      
      return mp[curkey]=ans;
      
      
      
      
      
    }
};
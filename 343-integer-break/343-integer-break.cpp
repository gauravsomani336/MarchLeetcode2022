class Solution {
public:
    int integerBreak(int n) {
       return solve(1,n,0) ;
    }
    int solve(int cur, int amount,int k)
    {
        // if(amount<0)
        // {
        //     return 0;
        // }
        if(amount==0)
        {
            return k>=2?1:0;
        }
        if(cur>amount)
        {
            return 0;
        }
        
        int consider=0;
        
        if(cur <= amount)
        {
            consider=cur* solve(cur,amount-cur,k+1);
        }
        int notConsider=solve(cur+1,amount,k);
        
        return max(consider,notConsider);
    }
};
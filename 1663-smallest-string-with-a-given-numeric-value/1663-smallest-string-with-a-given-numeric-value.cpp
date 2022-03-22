class Solution {
public:
    string getSmallestString(int n, int k) {
           string res(n,'a');
         k-=n;
        n-=1;
        while(k>0)
        {
            res[n]+=min(25,k);
            n-=1;
            k-=min(25,k);
        }
        
        return res;
    }
};
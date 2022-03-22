class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k-=n;
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)
            {
                break;
            }
            else if(k<25)
            {
                res[i]=(char)res[i]+k;
                k=0;
            }
            else if(k>=25)
            {
                res[i]=(char)res[i]+25;
                k-=25;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>l(26,0);
        vector<int>res;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            l[s[i]-'a']=i;
        }
        
        int start=0;
       int last=INT_MIN;
        for(int i=0;i<n;i++)
        {
            last=max(last, l[s[i]-'a']);
                if(last==i)
                {
                    res.push_back((last-start)+1);
                    start=last+1;
                }
        }
        return res;
        
        
    }
};
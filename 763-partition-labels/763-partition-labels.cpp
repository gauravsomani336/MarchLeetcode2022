class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastOccurence(26,0);
        vector<int>res;
        for(int i=0;i<s.size();i++)
        {
            lastOccurence[s[i]-'a']=i;
        }
        int start=0;
        int last=0;
        for(int i=0;i<s.size();i++)
        {
            last=max(last,lastOccurence[s[i]-'a']);
            if(last==i)
            {
                res.push_back((last-start)+1);
                start=i+1;
            }
        }
        return res;
        
    }
};
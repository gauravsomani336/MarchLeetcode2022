class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a, pair<int,int>&b)
        {
            return a.first==b.first? a.second<b.second:a.first<b.first;
        }
    }cmpare;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>res;
        vector<pair<int,int>>vec;
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    count+=1;
                }
            }
            vec.push_back({count,i});
        }
        
        sort(vec.begin(), vec.end(), cmpare);
        
        for(auto x:vec)
        {
            if(k==0)
            {
                break;
            }
            
            res.push_back(x.second);
            k-=1;
        }
        return res;
    }
};
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int> freqA(7),freqB(7),same(7);
        for(int i=0;i<n;i++)
        {
            freqA[tops[i]]+=1;
            freqB[bottoms[i]]+=1;
            
             if(tops[i] == bottoms[i])
                ++same[tops[i]];
        }
        int mn=INT_MAX;
        for(int i=1;i<=6;i++)
        {
            if(freqA[i]+freqB[i]-same[i]==n)
            {
                mn=min(mn,min(freqA[i],freqB[i])-same[i]);
            }
        }
        return mn==INT_MAX?-1:mn;
    }
};
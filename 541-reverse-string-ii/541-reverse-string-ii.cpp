class Solution {
public:
    string reverseStr(string s, int k) {
        int idx=0;
        while(idx<s.length())
        {
            reverse(s.begin()+idx, s.begin()+idx+k>s.end()?s.end():s.begin()+idx+k);
            idx=idx+2*k;
            
        }
        return s;
    }
};
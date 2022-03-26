/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>vec;
        if(n==0)
        {
            return vec;
        }
        return solve(1,n);
    }
    
    vector<TreeNode*>solve(int start, int end)
    {
        vector<TreeNode*>vec;
        if(start>end)
        {
            vec.push_back(NULL);
            return vec;
        }
        
        for(int i=start;i<=end;i++)
        {
            auto left_sub= solve(start, i-1);
            
            auto right_sub=solve(i+1, end);
            
            for(auto l: left_sub)
            {
                for(auto r: right_sub)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    
                    vec.push_back(root);
                }
            }
        }
        return vec;
        
    }
};
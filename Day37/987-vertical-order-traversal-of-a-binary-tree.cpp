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
    void traverse(int lorr, map<int, vector<pair<int, int>>> &vals, TreeNode* root, int row, int col)
    {
        if(root)
        {
            vals[col + lorr].push_back({row + 1, root->val}); 
            traverse(-1, vals, root->left, row + 1, col + lorr);
            traverse(1, vals, root->right, row + 1, col + lorr);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, vector<pair<int, int>>> vals;
        traverse(0, vals, root, 0, 0);
        vector<vector<int>> ans;
        for(auto x: vals)
        {
            ans.push_back({});
            sort(x.second.begin(), x.second.end());
            for(auto y: x.second)
            {
                ans.back().push_back(y.second);
            }
        }
        return ans;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root) 
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int dir = 1;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> a(sz);
            for(int i = 0; i < sz; i++)
            {
                int idx = dir ? i : sz - 1 - i;
                a[idx] = (q.front()->val);
                if(q.front()->left)  
                    q.push(q.front()->left);
                if(q.front()->right) 
                    q.push(q.front()->right);
                q.pop();
            }
            dir = 1 - dir;
            ans.push_back(a);
        }
        return ans;
    }
};

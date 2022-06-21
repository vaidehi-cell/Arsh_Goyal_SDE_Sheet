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
    vector<int> inn;
    void inOrder(TreeNode* rt)
    {
        if(rt)
        {
            inOrder(rt->left);
            inn.push_back(rt->val);
            inOrder(rt->right);
        }
        else
            return;
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        inOrder(root);
        return inn;
    }
};

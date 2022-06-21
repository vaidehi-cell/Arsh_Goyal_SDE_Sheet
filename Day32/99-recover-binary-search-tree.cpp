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
    TreeNode* first, *second, *prev;
    void inorder(TreeNode* rt)
    {
        if(rt)
        {
            inorder(rt->left);
            if(!first && prev && rt->val < prev->val)
                first = prev;
            if(first && prev && rt->val <= prev->val)
                second = rt;
            prev = rt;
            inorder(rt->right);
        }
    }
    void recoverTree(TreeNode* root) 
    {
        prev = NULL;
        inorder(root);
        swap(first->val, second->val);
    }
};

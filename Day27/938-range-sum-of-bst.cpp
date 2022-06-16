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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(root)
        {
            int x = 0, y = 0;
            if(root->left)
                x = rangeSumBST(root->left, low, high);
            if(root->right)
                y = rangeSumBST(root->right, low, high);
            if(root->val <= high && root->val >= low)
                return root->val + x + y;
            else
                return x + y;
        }
        else
            return 0;
    }
};

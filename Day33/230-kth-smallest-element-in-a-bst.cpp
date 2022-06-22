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
    int ans = -1;
    void intraverse(TreeNode* root, int &c, int k)
    {
        if(ans != -1 || !root)
            return;
        intraverse(root->left, c, k);
        c++;
        if(c == k)
        {
            ans = root->val;
            return;
        }
        if(ans == -1)
            intraverse(root->right, c, k);   
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int c = 0;
        intraverse(root, c, k);
        return ans;
    }
};

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
    void visit(TreeNode* node, TreeNode* parent, set<TreeNode*> &visited, int &ans)
    {
        if(node)
        {
            visit(node->left, node, visited, ans);
            visit(node->right, node, visited, ans);
            if(!parent && visited.find(node) == visited.end() || visited.find(node->left) == visited.end() || visited.find(node->right) == visited.end())
            {
                ans++;
                visited.insert(node);
                visited.insert(parent);
                visited.insert(node->left);
                visited.insert(node->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) 
    {
        int ans = 0;
        set<TreeNode*> visited;
        visited.insert(NULL);
        visit(root, NULL, visited, ans);
        return ans;
    }
};

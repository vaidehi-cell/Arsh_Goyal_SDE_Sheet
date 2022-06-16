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
class BSTIterator {
public:
    vector<TreeNode*> nodes;
    TreeNode* BSTIt;
    int i = 0;
    
    void intraverse(TreeNode* rt)
    {
        if(rt)
        {
            intraverse(rt->left);
            nodes.push_back(rt);
            intraverse(rt->right);
        }
    }
    
    TreeNode* smallest(TreeNode* rt)
    {
        if(rt)
        {
            if(rt->left)
                return smallest(rt->left);
            else
                return rt;
        }
        else
            return rt;
    }
    
    BSTIterator(TreeNode* root) 
    {
        int smVal = smallest(root)->val - 1;
        TreeNode* BSTIt = new TreeNode(smVal);
        smallest(root)->left = BSTIt;
        intraverse(root);
    }
    
    int next() 
    {
        i++;
        return nodes[i]->val;
    }
    
    bool hasNext() 
    {
        if(i + 1 < nodes.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

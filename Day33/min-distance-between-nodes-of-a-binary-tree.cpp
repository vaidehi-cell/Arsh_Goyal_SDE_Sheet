/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
    public:
    Node *lca(Node *root, int a, int b) 
    {
        if(!root)
            return NULL;
        if(root->data == a || root->data == b)
            return root;
        Node* left = lca(root->left, a, b), *right = lca(root->right, a, b);
        if(left && right)
            return root;
        if(left)
            return left;
        else
            return right;
    } 
    int level(Node* root, int x, int l)
    {
        if(!root)
            return -1;
        if(root->data == x)
            return l;
        int left = level(root->left, x, l+1);
        if(left == -1)
            return level(root->right, x, l+1);
        return left;
    }
    int findDist(Node* root, int a, int b) 
    {
        Node* lcaa = lca(root, a, b);
        return level(lcaa, a, 0) + level(lcaa, b, 0);
    }
};

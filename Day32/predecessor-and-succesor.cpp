void succ(Node* root, Node* &suc, int key)
{
    while(root)
    {
        if(root->key <= key)
            root = root->right;
        else
        {
            suc = root;
            root = root->left;
        }
    }
}

void  pred(Node* root, Node* &pre, int key)
{
    while(root)
    {
        if(root->key >= key)
            root = root->left;
        else
        {
            pre = root;
            root = root->right;
        }
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pred(root, pre, key);
    succ(root, suc, key);
}

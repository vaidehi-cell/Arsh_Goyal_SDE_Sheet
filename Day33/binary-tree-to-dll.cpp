/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* prev = NULL;
    Node* head = NULL;
    void inorder(Node* node)
    {
        if(!node)
            return;
        inorder(node->left);
        node->left = prev;
        if(!prev)
            head = node;
        else
            prev->right = node;
        prev = node;
        inorder(node->right);
    }
    Node * bToDLL(Node *root)
    {
        inorder(root);
        return head;
    }
};

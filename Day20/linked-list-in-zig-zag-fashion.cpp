struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution
{
    public:
    void zigRecursive(Node* head, bool flag)
    {
        if (!head || !head->next)
            return;
        if(flag) 
        {
            if(head->data > head->next->data)
                swap(head->data, head->next->data);
            zigRecursive(head->next, !flag);
        }
        else 
        {
            if(head->data < head->next->data)
                swap(head->data, head->next->data);
            zigRecursive(head->next, !flag);
        }
    }
    Node *zigZag(Node *head)
    {
        zigRecursive(head, true);
        return head;
    }
};

/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* nex = NULL;
    while(curr)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
    return head;
}

Node* subtract(Node* larger, Node* smaller)
{
    larger = reverse(larger);
    smaller = reverse(smaller);
    Node *l2 = smaller, *l1 = larger;
    Node *ans = new Node(0), *temp = ans;
    while(l1->next && l2->next)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1->next)
    {
        Node*n = new Node(0);
        l2->next = n;
        l2 = l2->next;
        l1 = l1->next;
    }
    int rem = 0;
    l1 = larger, l2 = smaller;
    
    while(l1 and l2)
    {
        int diff = l1->data - l2->data;
        if(diff - rem >= 0)
        {
            Node* newnode = new Node(diff - rem);
            temp->next = newnode;
            temp = temp->next;
            rem = 0;
        }
        else
        {
            int val = (diff - rem + 10);
            Node* newnode = new Node(val);
            temp->next = newnode;
            temp = temp->next;
            rem = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    Node *res = ans->next;
    res = reverse(res);
    if(res->data == 0) 
        return res->next;
    return res;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    
    if(!(l1->next) and l1->data == 0) 
        return l2;
    if(!(l2->next) and l2->data == 0) 
        return l1;
    
    while(l1->data == 0) 
        l1 = l1->next;
    while(l2->data == 0) 
        l2 = l2->next;
        
    Node* t1 = l1;
    Node* t2 = l2;
    int len1 = 0, len2 = 0;
    while(t1)
    {
        len1++;
        t1 = t1->next;
    }
    while(t2)
    {
        len2++;
        t2 = t2->next;
    }
    
    if(len1 > len2)
        return subtract(l1, l2);
    else if(len1 < len2)
        return subtract(l2, l1);
    else
    { 
        while(l1 && l2)
        {
            if(l1->data > l2->data)
                return subtract(l1, l2);
            else if(l1->data < l2->data)
                return subtract(l2,l1);
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }
        } 
        Node* newnode = new Node(0);
        newnode->next = NULL;
        return newnode;
    }
    return NULL;
}

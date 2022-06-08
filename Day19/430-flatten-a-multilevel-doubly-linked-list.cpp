/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(!head)
            return NULL;
        Node* curr = head;
        while(curr) 
        {
            if (curr->child) 
            {
                Node* next = curr->next;
                Node* child = flatten(curr->child);
                curr->child = NULL;
                curr->next = child;
                child->prev = curr;
                while (curr->next) 
                    curr = curr->next;
                curr->next = next;
                if(next) 
                    next->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

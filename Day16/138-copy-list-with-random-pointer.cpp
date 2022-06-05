/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return NULL;
        Node* newhead = new Node(head->val);
        map<Node*, Node*> copy;
        copy[head] = newhead;
        Node* temp = head->next, *curr = newhead;
        
        while(temp)
        {
            curr->next = new Node(temp->val);
            copy[temp] = curr->next;
            temp = temp->next;
            curr = curr->next;
        }
        
        temp = head;
        curr = newhead;
        
        while(curr)
        {
            curr->random = copy[temp->random];
            curr = curr->next;
            temp = temp->next;
        }
        return newhead;
    }
};

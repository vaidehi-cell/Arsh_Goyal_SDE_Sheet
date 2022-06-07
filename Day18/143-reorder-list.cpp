/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev, ListNode* next) 
    {
        ListNode* curr = head; 
        while(curr) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next)
            return;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head1 = slow->next;
        slow->next = NULL;
        ListNode *curr2 = reverseList(head1, NULL, NULL), *curr1 = head, *temp1, *temp2;
        while(curr1 || curr2)
        {
            if(curr1) 
            {
                temp1 = curr1->next;
                curr1->next = curr2;
                curr1 = temp1;
            }
            if(curr2) 
            {
                temp2 = curr2->next; 
                curr2->next = temp1;
                curr2 = temp2;
            }
        }
    }
};

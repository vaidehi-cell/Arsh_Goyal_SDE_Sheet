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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* h1 = head, * h2 = head, *prev = NULL;
        int x = n;
        while(x--)
            h2 = h2->next;
        if(h2 == NULL)
            return head->next;
        while(h1 && h2)
        {
            prev = h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        if(prev)
        {
            prev->next = h1->next;
            return head;
        } 
        return NULL;
    }
};

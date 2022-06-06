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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head == NULL || head->next == NULL || left == right)
            return head;
        else
        {
            ListNode *curr = head, *prev = NULL;
            while(left > 1)
            {
                prev = curr;
                curr = curr->next;
                left--;
                right--;
            }
            ListNode *head1 = prev, *tail = curr, *third = NULL;
            while(right)
            {
                third = curr->next;
                curr->next = prev;
                prev = curr;
                curr = third;
                right--;
            }
            if(head1)
                head1->next = prev;
            else
                head = prev;
            tail->next = curr;
            return head;
        }
    }
};

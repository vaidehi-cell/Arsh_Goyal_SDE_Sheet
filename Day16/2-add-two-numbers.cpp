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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head1 = l1, *head2 = l2;
        ListNode *head3 = new ListNode((l1->val + l2->val)%10);
        int x = (l1->val + l2->val)/10;
        head1 = head1->next;
        head2 = head2->next;
        ListNode* tmp = head3;
        while(head1 && head2)
        {
            ListNode* nn = new ListNode((x+head1->val+head2->val)%10);
            head3->next = nn;
            head3 = head3->next;
            x = (x + head1->val + head2->val)/10;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1)
        {
            ListNode* nn = new ListNode((x + head1->val) % 10);
            head3->next = nn;
            head3 = head3->next;
            x = (x + head1->val)/10;
            head1 = head1->next;
        }
        while(head2)
        {
            ListNode* nn = new ListNode((x + head2->val) % 10);
            head3->next = nn;
            head3 = head3->next;
            x = (x + head2->val)/10;
            head2 = head2->next;
        }
        if(x > 0)
        {
            ListNode* nn = new ListNode(x % 10);
            head3->next = nn;
            head3 = head3->next;
        }
        return tmp;
    }
};

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
        string a = "", b = "", c = "";
        ListNode *ans = NULL;
        while(l1)
        {
            a += '0' + l1->val;
            l1 = l1->next;
        }
        while(l2)
        {
            b += '0' + l2->val;
            l2 = l2->next;
        }
        int x = a.size(), y = b.size(), rem = 0;
        while(x && y)
        {
            int curr = a[x-1]-'0' + b[y-1]-'0' + rem;
            rem = curr / 10;
            ans = new ListNode(curr % 10, ans);
            x--, y--;
        }
        while(x)
        {
            int curr = a[x-1] - '0' + rem;
            rem = curr / 10;
            ans = new ListNode(curr % 10, ans);
            x--;
        }
        while(y)
        {
            int curr = b[y-1] - '0' + rem;
            rem = curr / 10;
            ans = new ListNode(curr % 10, ans);
            y--;
        }
        if(rem)
            ans = new ListNode(rem, ans);
        return ans;
    }
};

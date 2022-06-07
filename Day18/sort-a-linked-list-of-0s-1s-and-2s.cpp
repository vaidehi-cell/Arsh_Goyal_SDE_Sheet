class ListNode
{
    public:
        int val;
        ListNode * next = NULL;
};
ListNode* solve(ListNode *head)
{
    ListNode *res = head, *ans = head;
    int zero = 0, one = 0, two = 0;
    while(head)
    {
        if(head->val == 0)
            zero++;
        else if(head->val == 1)
            one++;
        else
            two++;
        head = head->next;
    }
    while(res)
    {
        if(zero)
        {
            zero--;
            res->val = 0;
        }
        else if(one)
        {
            one--;
            res->val = 1;
        }
        else
        {
            two--;
            res->val = 2;
        }
        //cout << res->val << " ";
        res = res->next;
    }
    return ans;
}

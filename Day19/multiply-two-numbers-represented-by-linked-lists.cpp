void solve(ListNode *a, ListNode *b)
{
    ll num1 = 0, num2 = 0;
    while(a)
    {
        num1 *= 10;
        num1 += a->val;
        a = a->next;
    }
    while(b)
    {
        num2 *= 10;
        num2 += b->val;
        b = b->next;
    }
    return num1*num2;
}

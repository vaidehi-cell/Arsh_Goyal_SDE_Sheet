void solve(ListNode *delete)
{
    if(!delete)
        return;
    ListNode *prev = delete;
    while(delete->next)
    {
        prev = delete;
        delete->val = delete->next->val;
        delete = delete->next;
    }
    prev->next = NULL;
}
//Shift all nodes left

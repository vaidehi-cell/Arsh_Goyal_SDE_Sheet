class MyStack
{
public:
    deque<int> d;
    void push(int x)
    {
        d.push_back(x);
    }
    int pop()
    {
        if(d.size())
        {
            int x = d.back();
            d.pop_back();
            return x;
        }
        return -1;
    }
    int top()
    {
        if(d.size())
            return d.back();
        return -1;
    }
    bool empty()
    {
        return d.size() == 0;
    }
};

class MyQueue
{
public:
    deque<int> d;
    void push(int x)
    {
        d.push_back(x);
    }
    int pop()
    {
        if(d.size())
        {
            int x = d.front();
            d.pop_front();
            return x;
        }
        return -1;
    }
    int front()
    {
        if(d.size())
            return d.front();
        return -1;
    }
    bool empty()
    {
        return d.size() == 0;
    }
};

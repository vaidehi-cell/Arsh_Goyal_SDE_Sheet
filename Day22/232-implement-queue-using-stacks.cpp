class MyQueue {
public:
    stack<int> s1, s2;
    int curr;
    MyQueue() 
    {
        curr = 0;
    }
    
    void push(int x) 
    {
        if(s1.empty())
            curr = x;
        while(!s1.empty())
        {
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty())
        {
            int val = s2.top();
            s1.push(val);
            s2.pop();
        }
    }
    
    int pop() 
    {
        int val = s1.top();
        s1.pop();
        if(!s1.empty())
            curr = s1.top();
        return val;
    }
    
    int peek() 
    {
        return curr;
    }
    
    bool empty() 
    {
        return s1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

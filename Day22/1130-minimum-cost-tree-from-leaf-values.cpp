class Solution {
public:
   int mctFromLeafValues(vector<int>& a) 
   {
       if(a.size() == 2)
           return a[0] * a[1];
       int sum = 0;
       while(a.size() > 1)
       {
           int product = INT_MAX, idx = -1;
           for(int i = 1; i < a.size(); i++)
           {
               if(product > a[i]*a[i-1])
               {
                   if(a[i] < a[i-1])
                       idx = i;
                   else
                       idx = i-1;
                   product = a[i]*a[i-1];
               }
           }
           sum += product;  
           a.erase(a.begin() + idx);
       }
       return sum;
   }
};

/*Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.*/

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int sum = 0, curr = 0, index = 0;
        for(int i = 0; i < n; i++)
        {
            int x = p[i].petrol - p[i].distance;
            sum += x;
            curr += x;
            if(curr < 0)
            {
                curr = 0;
                index = i + 1;
            }
        }
        return sum < 0 ? -1 : index;
    }
};

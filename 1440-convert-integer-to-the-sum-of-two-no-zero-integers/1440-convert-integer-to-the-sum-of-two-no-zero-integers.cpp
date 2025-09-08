class Solution {
public:

    bool check(int n)
    {
        //if there is atleast one digit 0 so return false
       // cout<<"n "<<n<<endl;
        while(n!=0)
        {
            
            int digit=n%10;
          //  cout<<"digit "<<digit<<endl;
            if(digit==0)return false;
            n/=10;
        }
        return true;
    }


    vector<int> getNoZeroIntegers(int n) {
        //we just need to ruturn 2 numbers not having 0 and their sum =n 
        
      int start=1;int end=n-1;
      while(start<=end)
      {
        //so we will try this 2 possible numbers 
        //we ensure that sum of both is always n so the remaining is the second condition 
        if(check(start)==true&&check(end)==true)
        {
            return {start,end};
        }
        start++;end--;
      }
      return {start,end};
    }
};
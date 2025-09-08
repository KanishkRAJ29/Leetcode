class Solution
{
    public:
    
    std::vector<int> getNoZeroIntegers(const int n)
    {
        for(int a{1}; a<n; ++a)
        {
            int b{n-a};
            const auto no_zeros=[&](int num)
            {
                for(; num>0; num/=10)
                    if(num%10==0)
                        return false;
                return true;
            };
            if(no_zeros(b) && no_zeros(a))
                return std::vector{a,n-a};
        }
        return std::vector{-1, -1};
    }
};
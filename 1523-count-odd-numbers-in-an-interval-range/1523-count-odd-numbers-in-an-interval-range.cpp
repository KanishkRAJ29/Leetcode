class Solution {
public:
    int countOdds(int low, int high) {
        return int(int(low%2==1)+(high-low+1-int(low%2==1))/2);
    }
};
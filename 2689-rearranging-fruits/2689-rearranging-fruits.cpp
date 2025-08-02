class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
    // 1. Count fruit frequencies and find the overall minimum cost fruit.
    // The map 'mp' will store the difference in counts.
    // mp[x] > 0 means basket1 has a surplus of fruit x.
    // mp[x] < 0 means basket2 has a surplus of fruit x.
    unordered_map<int,int> mp;
    int globalMin=INT_MAX;
    for (int x : b1){ 
        mp[x]++;
        globalMin=min(globalMin,x);
    }
    for (int x : b2){ 
        mp[x]--;
        globalMin=min(globalMin,x);
    }

    // 2. Identify fruits to be swapped and check for impossibility.
    // 'pos' stores fruits basket1 must give away: {cost, count}.
    // 'neg' stores fruits basket2 must give away: {cost, count}.
    vector<pair<int,int>> pos, neg;
    for (auto& [x,c] : mp) {
        if (c == 0) continue; // This fruit is already balanced.
        // The total count of a fruit must be even. If the difference 'c'
        // is odd, the total count is also odd, making it impossible.
        if (abs(c) % 2 != 0) return -1;
        
        if (c > 0) { // basket1 has c extra fruits of cost x. It must give away c/2.
            pos.emplace_back(x, c/2);
        } else { // basket2 has -c extra fruits. It must give away -c/2.
            neg.emplace_back(x, (-c)/2);
        }
    }
    
    // NOTE: The original code has a check `if (pos.size() != neg.size()) return -1;`
    // This check is incorrect, as the number of *types* of surplus fruits doesn't
    // have to be equal, only the total *count* of surplus fruits (which is guaranteed
    // if the %2 checks pass). The rest of the logic is sound.

    // 3. Perform greedy swaps using heaps to minimize cost.
    // A min-heap for basket1's surplus to get the cheapest fruit efficiently.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minheap(pos.begin(), pos.end());
    // A max-heap for basket2's surplus to get the most expensive fruit efficiently.
    priority_queue<pair<int,int>> maxheap(neg.begin(), neg.end());

    long long ans=0;
    int twoswaps=2*globalMin; // Cost of an indirect swap.
    
    // Loop until all surplus fruits are swapped.
    while(minheap.size()!=0){
        // Get the cheapest fruit 'x' from basket1's surplus.
        auto [x,y]=minheap.top();
        minheap.pop();
        // Get the most expensive fruit 'a' from basket2's surplus.
        auto [a,b]=maxheap.top();
        maxheap.pop();
        
        // Calculate the cost for this optimal pairing.
        int minCost=min({x, a, twoswaps}); // Equivalent to min(min(x,a), twoswaps)
        
        int num_swaps = min(y, b); // Number of swaps we can do with this pair.
        ans += (long long)num_swaps * minCost;

        // If there are remaining fruits of either type, add them back to the heap.
        if(y > b){
            minheap.push({x, y - b});
        } else if(b > y){
            maxheap.push({a, b - y});
        }
    }
    return ans;
}
};
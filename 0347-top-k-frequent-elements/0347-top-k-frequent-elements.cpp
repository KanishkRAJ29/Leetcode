#include <vector>
#include <unordered_map>
#include <queue>
#include <utility> // for std::pair

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        // Min-heap based on frequency
        using Pair = std::pair<int, int>; // pair of (frequency, number)
        auto cmp = [](const Pair& a, const Pair& b) {
            return a.first > b.first; // Min-heap based on frequency
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> minHeap(cmp);
        
        // Push the frequency and number into the heap
        for (const auto& entry : frequencyMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // Maintain the size of the heap to k
            }
        }
        
        // Extract the top k elements
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // Get the number
            minHeap.pop();
        }
        
        // Since we need to return the top k frequent elements,
        // we may need to reverse the result as we used a min-heap.
       
        
        return result;
    }
};

class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int total = 0;
        // work on our own copy so we can push_back without disturbing caller
        vector<int> boxes = initialBoxes;
        
        // status[i]: 0 = closed, 1 = open & unprocessed, 2 = already processed
        bool progress = true;
        while (progress) {
            progress = false;
            int sz = boxes.size();
            // try to process every box we currently “have”
            for (int i = 0; i < sz; ++i) {
                int b = boxes[i];
                // only open AND not yet processed
                if (status[b] != 1) 
                    continue;
                
                // collect its candies
                total += candies[b];
                status[b] = 2;           // mark “processed”
                progress = true;         // we made progress this round
                
                // use any new keys
                for (int k : keys[b]) {
                    if (status[k] == 0) {
                        status[k] = 1;   // open it
                    }
                }
                // pick up any boxes inside
                for (int nb : containedBoxes[b]) {
                    boxes.push_back(nb);
                }
            }
        }
        
        return total;
    }
};

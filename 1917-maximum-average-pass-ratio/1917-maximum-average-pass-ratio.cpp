
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) -> double {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        priority_queue<pair<double,int>> pq; // max-heap by gain
        int n = (int)classes.size();

        for (int i = 0; i < n; ++i) {
            pq.push({ gain(classes[i][0], classes[i][1]), i });
        }

        while (extraStudents--) {
            auto [g, i] = pq.top(); pq.pop();
            classes[i][0]++; // add one guaranteed pass
            classes[i][1]++;
            pq.push({ gain(classes[i][0], classes[i][1]), i });
        }

        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += (double)classes[i][0] / classes[i][1];
        }
        return sum / n;
    }
};

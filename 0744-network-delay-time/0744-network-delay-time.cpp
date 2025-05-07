class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({k, 0});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while (!pq.empty()) {
            auto [node, time] = pq.top();
            pq.pop();
            for (auto [nie, t] : adj[node]) {
                if (t + time < dist[nie]) {
                    dist[nie] = time + t;
                    pq.push({nie, dist[nie]});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return (ans==INT_MAX)?-1:ans;
    }
};
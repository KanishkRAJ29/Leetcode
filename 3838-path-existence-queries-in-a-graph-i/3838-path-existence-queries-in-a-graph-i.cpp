class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        else return parent[x]=find(parent[x]);
    }
    void unionFind(int x,int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp)return;
        if(rank[xp]>rank[yp]){
            parent[yp]=xp;
        }else if(rank[yp]>rank[xp]){
            parent[xp]=yp;
        }else{
            parent[xp]=yp;
            rank[yp]++;
        }
        return;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<pair<int,int>>graph;
        int i=0;
        int j=1;
        while(j<n){
            if(nums[j]-nums[i]<=maxDiff){
                graph.push_back({i,j});
            }
            while(nums[j]-nums[i]>maxDiff){
                i++;
                if(nums[j]-nums[i]<=maxDiff){
                graph.push_back({i,j});
                }
            }
            j++;
        }

        for( i=0;i<graph.size();i++){
            unionFind(graph[i].first,graph[i].second);
        }
        vector<bool>ans;
        for( i=0;i<queries.size();i++){
            if(parent[queries[i][0]]==parent[queries[i][1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
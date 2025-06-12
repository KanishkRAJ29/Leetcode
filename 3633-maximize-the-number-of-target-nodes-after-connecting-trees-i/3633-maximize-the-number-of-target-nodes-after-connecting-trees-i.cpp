class Solution {
public:
    int bfs(int curr,unordered_map<int,vector<int>>&adj,int dist,int N){
        queue<pair<int,int>>q;
        q.push({curr,0});
        vector<bool>vis(N,false);
        vis[curr]=true;
        int count=0;
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            if(dist<d)continue;
            count++; //include current node in targetNodes count
            //visit neighbors of currNode
            for(auto &ngbr : adj[node]) {
                if(!vis[ngbr]) {
                    vis[ngbr] = true;
                    q.push({ngbr, d+1});
                }
            }
        }
        return count;

    }
    vector<int>findCount(vector<vector<int>>&edges,int dist){
        unordered_map<int,vector<int>>adj;
        int N=edges.size()+1;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(N);
        for(int i=0;i<N;i++){
            result[i]=bfs(i,adj,dist,N);
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N=edges1.size()+1;
        vector<int>result=findCount(edges1,k);
        vector<int>res=findCount(edges2,k-1);
        int maxi=*max_element(res.begin(),res.end());
        for(int i=0;i<N;i++){
            result[i]+=maxi;
        }
        return result;
    }
};
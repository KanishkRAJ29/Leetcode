class Solution {
public:
        unordered_map<int,vector<int>>giveAdj(vector<vector<int>>&edges){
            unordered_map<int,vector<int>>adj;
            for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        }
    void dfs(int curr,vector<int>&marking,unordered_map<int,vector<int>>&adj,int& zeros,int& ones,int parent){
        if(marking[curr]==0)zeros++;
        else ones++;

        for(auto &ngbr:adj[curr]){
            if(ngbr==parent)continue;
            marking[ngbr]=(marking[curr]==0) ? 1 : 0;
            dfs(ngbr,marking,adj,zeros,ones,curr);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        unordered_map<int,vector<int>>adj1=giveAdj(edges1);
        unordered_map<int,vector<int>>adj2=giveAdj(edges2);
        int zmA=0;//zero marked in A
        int omA=0;//one marked in A
        vector<int>markingA(n,-1);
        markingA[0]=0;
        dfs(0,markingA,adj1,zmA,omA,-1);

        int zmB=0;//zero marked in B
        int omB=0;//one marked in B
        vector<int>markingB(m,-1);
        markingB[0]=0;
        dfs(0,markingB,adj2,zmB,omB,-1);
        int maxi=max(omB,zmB);
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(markingA[i]==0){
                result[i]=zmA+maxi;
            }else{
                result[i]=omA+maxi;
            }
        }
        return result;
    }
};
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int &ind,vector<int>&groups,int g){
        if(vis[ind])return;
        vis[ind]=1;
        groups[ind]=g;
        for(int i:adj[ind]){
            dfs(adj,vis,i,groups,g);
        }
    
       
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>groups(c+1,0);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
           adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= c; ++i) {
            adj.try_emplace(i, vector<int>{});
        }
        int group=0;
        vector<int>vis(c+1,0);
        for(int i=1;i<groups.size();i++){
            
            if(groups[i]==0){
                group++;
                
                
                dfs(adj,vis,i,groups,group);
            }
        }
        vector<set<int>>sorted(group+1);
        for(int i=1;i<=c;i++){
            sorted[groups[i]].insert(i);
        }
        
        vector<int>ans;
        vector<int>on(c+1,1);
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==2){
                if(on[queries[i][1]]){
                sorted[groups[queries[i][1]]].erase(queries[i][1]);
                on[queries[i][1]]=0;
                    
                }
                
            }else{
                if(on[queries[i][1]]){
                    ans.push_back(queries[i][1]);
                }

                else {
                    auto &st=sorted[groups[queries[i][1]]];
                    if(st.empty())ans.push_back(-1);
                    else ans.push_back(*st.begin());
                    
                }
            }
        }
        return ans;
    }
};
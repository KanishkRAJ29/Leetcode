class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
       int n=colors.size();
       unordered_map<int,vector<int>>adj;
       vector<int>indeg(n,0);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        indeg[v]++;
       }
       
       queue<int>q;
       vector<vector<int>>dp(n,vector<int>(26,0));
       for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
            dp[i][colors[i]-'a']=1;
        }
       }
       int answer=0;
       int count=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;
            answer=max(answer,dp[u][colors[u]-'a']);
            for(int &v:adj[u]){
                for(int i=0;i<26;i++){
                    dp[v][i]=max(dp[v][i],dp[u][i]+(colors[v]-'a'==i));
                }
                indeg[v]--;
            if(indeg[v]==0)q.push(v);
            
            }
            
           
        }
        if(count<n)return -1;
        return answer;



    }
};